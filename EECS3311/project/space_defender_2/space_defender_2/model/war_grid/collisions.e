note
	description: "Summary description for {COLLISIONS}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

-- utility class handling collisions and their debugging strings
-- debugging strings are reported to the delayed components of STATE
-- we check collisions at the current location of the initiating entity
-- the assumption is that these routines are called only after the new location
-- has been assigned to the initiating entity

class
	COLLISIONS

create
	make_default

feature -- init

	make_default
		do
			-- nothing
			r_enemy_requested_abortion := 1
			r_enemy_died := 2
		end

feature -- enumerations

	r_enemy_requested_abortion: INTEGER
	r_enemy_died: INTEGER

feature -- handlers

	-- handle starfighter possible collision with other entities
	handle_starfighter_initiated_collision (target_code: INTEGER)
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			state_access: STATE_ACCESS
			state: STATE
		do
			war_grid := war_grid_access.m
			state := state_access.m
			if not war_grid.starfighter.is_dead then
				-- encoutering a projectile
				across
					war_grid.projectiles is projectile
				loop
					if
					(projectile.row_loc = war_grid.starfighter.row_loc)
					and
					(projectile.col_loc = war_grid.starfighter.col_loc)
					and
					(not projectile.is_dead)
					then
						-- kill projectile and deduct starfighter health
						projectile.kill (0, "Starfighter")
						war_grid.starfighter.health := war_grid.starfighter.health - war_grid.max_of_two_integers (projectile.damage - war_grid.starfighter.armour, 0)
						if projectile.is_friendly then
							-- report starfighting colliding with friendly pojectile
							state.debug_string.insert_entry (target_code,
									generate_starfighter_collides_with_friendly_projectile_debug_string(projectile.id, projectile.damage - war_grid.starfighter.armour))
						else
							-- report starfighting colliding with enemy pojectile
							state.debug_string.insert_entry (target_code,
									generate_starfighter_collides_with_enemy_projectile_debug_string(projectile.id, projectile.damage - war_grid.starfighter.armour))
						end
						check_and_handle_starfighter_death (target_code)
					end
				end

				-- encountering an enemy
				across
					war_grid.enemies is enemy
				loop
					if
					(enemy.row_loc = war_grid.starfighter.row_loc)
					and
					(enemy.col_loc = war_grid.starfighter.col_loc)
					and
					(not enemy.is_dead)
					then
						 enemy.kill (0, "Starfighter")
						 war_grid.starfighter.health :=  war_grid.starfighter.health - enemy.health
						 -- report starfighter colliding with enemy
						 state.debug_string.insert_entry (state.debug_string.starfighter_action_code_delayed,
									generate_starfighter_collides_with_enemy_debug_string(enemy.get_enemy_name, enemy.id, enemy.health))
						-- report enemy death	
						check_and_report_enemy_death (enemy, state.debug_string.starfighter_action_code_delayed)
						check_and_handle_starfighter_death (state.debug_string.starfighter_action_code_delayed)
					end
				end
			end
		end

	-- handle friendly projectile possible collision with other entities
	-- can be used when spawning
	handle_friendly_projectile_initiated_collision (target_code: INTEGER ; initiating_friendly_projectile: PROJECTILE)
		require
			initiating_friendly_projectile.is_friendly = true
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			state_access: STATE_ACCESS
			state: STATE
		do
			war_grid := war_grid_access.m
			state := state_access.m

			if (not initiating_friendly_projectile.is_dead) and (initiating_friendly_projectile.is_on_grid) then
				-- encoutering a projectile
				across
					war_grid.projectiles is projectile
				loop
					if
					(projectile.row_loc = initiating_friendly_projectile.row_loc)
					and
					(projectile.col_loc = initiating_friendly_projectile.col_loc)
					and
					(projectile /= initiating_friendly_projectile)
					and
					(not projectile.is_dead)
					then
						if projectile.is_friendly then
							-- report initiating_friendly_projectile colliding with friendly pojectile
							projectile.kill (initiating_friendly_projectile.id, "*")
							initiating_friendly_projectile.damage := initiating_friendly_projectile.damage + projectile.damage
							state.debug_string.insert_entry (target_code,
								generate_projectile_to_projectile_collision_action_debug_string(initiating_friendly_projectile, projectile.is_friendly, projectile.id))

						else
							-- report initiating_friendly_projectile colliding with enemy pojectile
							if projectile.damage > initiating_friendly_projectile.damage then
								initiating_friendly_projectile.kill (projectile.id, "<")
								projectile.damage := projectile.damage - initiating_friendly_projectile.damage
							elseif projectile.damage < initiating_friendly_projectile.damage then
								projectile.kill (initiating_friendly_projectile.id, "*")
								initiating_friendly_projectile.damage := initiating_friendly_projectile.damage - projectile.damage
							else
								initiating_friendly_projectile.kill (projectile.id, "<")
								projectile.kill (initiating_friendly_projectile.id, "*")
							end
							state.debug_string.insert_entry (target_code,
								generate_projectile_to_projectile_collision_action_debug_string(initiating_friendly_projectile, projectile.is_friendly, projectile.id))
						end
					end
				end

				-- encountering an enemy
				across
					war_grid.enemies is enemy
				loop
					if
					(enemy.row_loc = initiating_friendly_projectile.row_loc)
					and
					(enemy.col_loc = initiating_friendly_projectile.col_loc)
					and
					(not enemy.is_dead)
					then
						-- report initiating_friendly_projectile colliding with an enemy
						initiating_friendly_projectile.kill (enemy.id, enemy.get_enemy_name)
						state.debug_string.insert_entry (target_code,
								generate_projectile_collides_with_entity_debug_string (initiating_friendly_projectile, enemy.id, enemy.get_enemy_name, initiating_friendly_projectile.damage-enemy.armour))
						enemy.health := enemy.health - war_grid.max_of_two_integers (initiating_friendly_projectile.damage-enemy.armour, 0)
						if enemy.health <= 0 then
							enemy.health := 0
							enemy.kill (initiating_friendly_projectile.id, "Projectile")
							state.debug_string.insert_entry (target_code, generate_enemy_death_debug_string (enemy))
						end
					end
				end

				-- encountering the starfighter
				if
				(war_grid.starfighter.row_loc = initiating_friendly_projectile.row_loc)
				and
				(war_grid.starfighter.col_loc = initiating_friendly_projectile.col_loc)
				and
				(not war_grid.starfighter.is_dead)
				then
					-- report initiating_friendly_projectile colliding with the starfighter
					initiating_friendly_projectile.kill (0, "Starfighter")
					state.debug_string.insert_entry (target_code,
								generate_projectile_collides_with_entity_debug_string (initiating_friendly_projectile, 0, "Starfighter", initiating_friendly_projectile.damage-war_grid.starfighter.armour))
					war_grid.starfighter.health := war_grid.starfighter.health - war_grid.max_of_two_integers (initiating_friendly_projectile.damage - war_grid.starfighter.armour, 0)
					check_and_handle_starfighter_death (target_code)
				end
			end
		end

	-- handle enemy projectile possible collision with other entities
	-- can be used when spawning
	handle_enemy_projectile_initiated_collision (target_code: INTEGER ; initiating_enemy_projectile: PROJECTILE)
		require
			initiating_enemy_projectile.is_friendly = false
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			state_access: STATE_ACCESS
			state: STATE
		do
			war_grid := war_grid_access.m
			state := state_access.m

			if (not initiating_enemy_projectile.is_dead) and (initiating_enemy_projectile.is_on_grid) then
				-- encoutering a projectile
				across
					war_grid.projectiles is projectile
				loop
					if
					(projectile.row_loc = initiating_enemy_projectile.row_loc)
					and
					(projectile.col_loc = initiating_enemy_projectile.col_loc)
					and
					(projectile /= initiating_enemy_projectile)
					and
					(not projectile.is_dead)
					then
						if projectile.is_friendly then
							-- report initiating_enemy_projectile colliding with friendly pojectile
							if projectile.damage > initiating_enemy_projectile.damage then
								initiating_enemy_projectile.kill (projectile.id, "<")
								projectile.damage := projectile.damage - initiating_enemy_projectile.damage
							elseif projectile.damage < initiating_enemy_projectile.damage then
								projectile.kill (initiating_enemy_projectile.id, "*")
								initiating_enemy_projectile.damage := initiating_enemy_projectile.damage - projectile.damage
							else
								initiating_enemy_projectile.kill (projectile.id, "<")
								projectile.kill (initiating_enemy_projectile.id, "*")
							end
							state.debug_string.insert_entry (target_code,
								generate_projectile_to_projectile_collision_action_debug_string(initiating_enemy_projectile, projectile.is_friendly, projectile.id))

						else
							-- report initiating_enemy_projectile colliding with enemy pojectile
							projectile.kill (initiating_enemy_projectile.id, "*")
							initiating_enemy_projectile.damage := initiating_enemy_projectile.damage + projectile.damage
							state.debug_string.insert_entry (target_code,
								generate_projectile_to_projectile_collision_action_debug_string(initiating_enemy_projectile, projectile.is_friendly, projectile.id))
						end
					end
				end

				-- encountering an enemy
				across
					war_grid.enemies is enemy
				loop
					if
					(enemy.row_loc = initiating_enemy_projectile.row_loc)
					and
					(enemy.col_loc = initiating_enemy_projectile.col_loc)
					and
					(not enemy.is_dead)
					then
						-- report initiating_enemy_projectile colliding with an enemy
						initiating_enemy_projectile.kill (enemy.id, enemy.get_enemy_name)
						enemy.health := war_grid.min_of_two_integers (enemy.health + initiating_enemy_projectile.damage, enemy.max_health)
						state.debug_string.insert_entry (target_code,
							generate_projectile_collides_with_entity_debug_string(initiating_enemy_projectile, enemy.id, enemy.get_enemy_name, initiating_enemy_projectile.damage))
					end
				end

				-- encountering the starfighter
				if
				(war_grid.starfighter.row_loc = initiating_enemy_projectile.row_loc)
				and
				(war_grid.starfighter.col_loc = initiating_enemy_projectile.col_loc)
				and
				(not war_grid.starfighter.is_dead)
				then
					-- report initiating_enemy_projectile colliding with the starfighter
					initiating_enemy_projectile.kill (0, "Starfighter")
					state.debug_string.insert_entry (target_code,
								generate_projectile_collides_with_entity_debug_string (initiating_enemy_projectile, 0, "Starfighter", initiating_enemy_projectile.damage-war_grid.starfighter.armour))
					war_grid.starfighter.health := war_grid.starfighter.health - war_grid.max_of_two_integers (initiating_enemy_projectile.damage - war_grid.starfighter.armour, 0)
					check_and_handle_starfighter_death (target_code)
				end
			end
		end

	-- handle enemy possible collision with other entities
	-- cannot be used when spawning, instead use: war_grid.run_enemy_spawn_collision_scenarios_at_loc
	-- returns true if another enemy encountered or if enemy died, resulting in abort action is needed. false otherwise
	handle_enemy_initiated_collision (target_code: INTEGER ; initiating_enemy: ENEMY): INTEGER
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			state_access: STATE_ACCESS
			state: STATE
		do
			war_grid := war_grid_access.m
			state := state_access.m

			if (not initiating_enemy.is_dead) and (initiating_enemy.is_on_grid) then
				-- encoutering a projectile
				across
					war_grid.projectiles is projectile
				loop
					if
					(projectile.row_loc = initiating_enemy.row_loc)
					and
					(projectile.col_loc = initiating_enemy.col_loc)
					and
					(not projectile.is_dead)
					then
						if projectile.is_friendly then
							-- report initiating_enemy colliding with friendly pojectile
							projectile.kill (initiating_enemy.id, initiating_enemy.get_enemy_name)
							initiating_enemy.health := initiating_enemy.health - war_grid.max_of_two_integers (projectile.damage - initiating_enemy.armour, 0)
							state.debug_string.insert_entry (target_code,
								generate_enemy_collision_with_projectile_debug_string(initiating_enemy, projectile.is_friendly, projectile.id, projectile.damage - initiating_enemy.armour))
							if initiating_enemy.health <= 0 then
								initiating_enemy.health := 0
								initiating_enemy.kill (projectile.id, "Projectile")
								state.debug_string.insert_entry (state.debug_string.enemy_action_code_delayed, initiating_enemy.generate_enemy_death_debug_string)
								Result := r_enemy_died
							end
						else
							-- report initiating_enemy colliding with enemy pojectile
							projectile.kill (initiating_enemy.id, initiating_enemy.get_enemy_name)
							initiating_enemy.health := war_grid.min_of_two_integers (initiating_enemy.health + projectile.damage, initiating_enemy.max_health)
							state.debug_string.insert_entry (target_code,
								generate_enemy_collision_with_projectile_debug_string(initiating_enemy, projectile.is_friendly, projectile.id, projectile.damage))
						end
					end
				end

				-- encountering an enemy
				across
					war_grid.enemies is enemy
				loop
					if
					(enemy.row_loc = initiating_enemy.row_loc)
					and
					(enemy.col_loc = initiating_enemy.col_loc)
					and
					(enemy /= initiating_enemy)
					and
					(not enemy.is_dead)
					then
						-- report initiating_enemy colliding with an enemy
						-- state.debug_string.insert_entry (target_code, generate_enemy_to_enemy_collision_debug_string (initiating_enemy))
						Result := r_enemy_requested_abortion
					end
				end

				-- encountering the starfighter
				if
				(war_grid.starfighter.row_loc = initiating_enemy.row_loc)
				and
				(war_grid.starfighter.col_loc = initiating_enemy.col_loc)
				and
				(not war_grid.starfighter.is_dead)
				then
					-- report initiating_enemy colliding with the starfighter
					initiating_enemy.kill (war_grid.starfighter.id, "Starfighter")
					state.debug_string.insert_entry (target_code, generate_enemy_to_enemy_collision_debug_string (initiating_enemy))
					check_and_report_enemy_death (initiating_enemy, target_code)
					war_grid.starfighter.health := war_grid.starfighter.health - initiating_enemy.health
					check_and_handle_starfighter_death (target_code)
				end
			end
		end

feature -- starfighter debugging strings

	generate_starfighter_collides_with_enemy_projectile_debug_string (p_projectile_id: INTEGER ; p_damage_taken: INTEGER): STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("      The Starfighter collides with enemy projectile(id:")
			Result.append (p_projectile_id.out)
			Result.append (") at location [")
			Result.append (war_grid.row_nb_to_letter (war_grid.starfighter.row_loc))
			Result.append (",")
			Result.append ((war_grid.starfighter.col_loc-1).out)
			Result.append ("], taking ")
			Result.append (p_damage_taken.out)
			Result.append (" damage.")
		end

	generate_starfighter_collides_with_friendly_projectile_debug_string (p_projectile_id: INTEGER ; p_damage_taken: INTEGER): STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("      The Starfighter collides with friendly projectile(id:")
			Result.append (p_projectile_id.out)
			Result.append (") at location [")
			Result.append (war_grid.row_nb_to_letter (war_grid.starfighter.row_loc))
			Result.append (",")
			Result.append ((war_grid.starfighter.col_loc-1).out)
			Result.append ("], taking ")
			Result.append (p_damage_taken.out)
			Result.append (" damage.")
		end

	generate_starfighter_collides_with_enemy_debug_string (p_enemy_name: STRING ; p_enemy_id: INTEGER ; p_damage_taken: INTEGER): STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("      The Starfighter collides with ")
			Result.append (p_enemy_name)
			Result.append ("(id:")
			Result.append (p_enemy_id.out)
			Result.append (") at location [")
			Result.append (war_grid.row_nb_to_letter (war_grid.starfighter.row_loc))
			Result.append (",")
			Result.append ((war_grid.starfighter.col_loc-1).out)
			Result.append ("], trading ")
			Result.append (p_damage_taken.out)
			Result.append (" damage.")
		end

	generate_starfighter_death_debug_string: STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("      The Starfighter at location [")
			Result.append (war_grid.row_nb_to_letter (war_grid.starfighter.row_loc))
			Result.append (",")
			Result.append ((war_grid.starfighter.col_loc-1).out)
			Result.append ("] has been destroyed.")
		end

feature -- general projectile debugging string

	generate_projectile_to_projectile_collision_action_debug_string
			(initiating_projectile: PROJECTILE ; is_friendly_projectile_encountered: BOOLEAN ; p_projectile_id: INTEGER): STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("      The projectile collides with ")
			if is_friendly_projectile_encountered then
				Result.append ("friendly projectile(id:")
			else
				Result.append ("enemy projectile(id:")
			end
			Result.append (p_projectile_id.out)
			Result.append (") at location [")
			Result.append (war_grid.row_nb_to_letter (initiating_projectile.row_loc))
			Result.append (",")
			Result.append ((initiating_projectile.col_loc-1).out)
			if (initiating_projectile.is_friendly and is_friendly_projectile_encountered) or
				(not initiating_projectile.is_friendly and not is_friendly_projectile_encountered) then
				Result.append ("], combining damage.")
			else
				Result.append ("], negating damage.")
			end
		end

	generate_projectile_collides_with_entity_debug_string
			(initiating_projectile: PROJECTILE ;  p_entity_id: INTEGER ; p_entity_name: STRING ; p_damage_dealth: INTEGER): STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("      The projectile collides with ")
			Result.append (p_entity_name)
			Result.append ("(id:")
			Result.append (p_entity_id.out)
			Result.append (") at location [")
			Result.append (war_grid.row_nb_to_letter (initiating_projectile.row_loc))
			Result.append (",")
			Result.append ((initiating_projectile.col_loc-1).out)
			if (not initiating_projectile.is_friendly) and (p_entity_id /= 0) then
				-- enemy projectile colliin with enemy
				Result.append ("], healing ")
			else
				Result.append ("], dealing ")
			end

			Result.append (p_damage_dealth.out)
			Result.append (" damage.")
		end

feature {NONE} -- enemy debugging strings

	generate_enemy_death_debug_string (enemy: ENEMY): STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("      The ")
			Result.append (enemy.get_enemy_name)
			Result.append (" at location [")
			Result.append (war_grid.row_nb_to_letter (enemy.row_loc))
			Result.append (",")
			Result.append ((enemy.col_loc-1).out)
			Result.append ("] has been destroyed.")
		end

	generate_enemy_collision_with_projectile_debug_string (initiating_enemy: ENEMY ; p_is_projectile_friendly: BOOLEAN ; p_projectile_id: INTEGER ; p_damage_taken: INTEGER): STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("      The ")
			Result.append (initiating_enemy.get_enemy_name)
			Result.append (" collides with ")
			if p_is_projectile_friendly then
				Result.append ("friendly projectile(id:")
			else
				Result.append ("enemy projectile(id:")
			end
			Result.append (p_projectile_id.out)
			Result.append (") at location [")
			Result.append (war_grid.row_nb_to_letter (initiating_enemy.row_loc))
			Result.append (",")
			Result.append ((initiating_enemy.col_loc-1).out)
			if p_is_projectile_friendly then
			Result.append ("], taking ")
			else
			Result.append ("], healing ")
			end
			Result.append (p_damage_taken.out)
			Result.append (" damage.")
		end

	generate_enemy_to_enemy_collision_debug_string (initiating_enemy: ENEMY): STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("      The ")
			Result.append (initiating_enemy.get_enemy_name)
			Result.append (" collides with ")
			Result.append (initiating_enemy.killed_by_entity_name)
			Result.append ("(id:")
			Result.append (initiating_enemy.killed_by_entity_id.out)
			Result.append (") at location [")
			Result.append (war_grid.row_nb_to_letter (initiating_enemy.row_loc))
			Result.append (",")
			Result.append ((initiating_enemy.col_loc-1).out) -- to account for the way we check collisions
			Result.append ("], trading ")
			Result.append (initiating_enemy.max_health.out)
			Result.append (" damage.")
		end

feature -- helper methods

	check_and_handle_starfighter_death (report_to_code: INTEGER)
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			state_access: STATE_ACCESS
			state: STATE
		do
			state := state_access.m
			war_grid := war_grid_access.m
			if war_grid.starfighter.health <= 0 then
				war_grid.starfighter.kill
				state.debug_string.insert_entry (report_to_code, generate_starfighter_death_debug_string)
			end
		end

	check_and_report_enemy_death (enemy: ENEMY ; report_to_code: INTEGER)
		local
			state_access: STATE_ACCESS
			state: STATE
		do
			state := state_access.m
			if (enemy.is_dead) then
				state.debug_string.insert_entry (report_to_code, generate_enemy_death_debug_string (enemy))
			end
			if (enemy.health <= 0) then
				enemy.health := 0
			end
		end

end

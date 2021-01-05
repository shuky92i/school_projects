note
	description: "Summary description for {WAR_GRID}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	WAR_GRID

inherit
	ANY
		redefine
			out
		end

create {WAR_GRID_ACCESS}
	make_empty

feature {NONE} -- Initialization

	-- make an empty grid
	make_empty
			-- Initialization for `Current'.
		do
			row_count := 0
			col_count := 0
			create grid.make_filled("_", row_count, col_count)

			-- Entity initialization
			create starfighter.make (row_count)
			create {ARRAYED_LIST[PROJECTILE]} projectiles.make (10)
			create {ARRAYED_LIST[ENEMY]} enemies.make (10)

			-- set enumaration values
		 	standard_movement := 0
			spread_movement_right := 1
			spread_movement_top_right := 2
			spread_movement_bottom_right := 3
			snipe_movement := 4
			rocket_movement := 5
			splitter_movement := 6
			enemy_left_movement := 7

			create collision_handler.make_default
		end

feature {SPACEWAR} -- Reshape/reset Grid, used only by SPACEWAR

	reshape (rows: INTEGER ; cols: INTEGER ; n1: INTEGER ; n2: INTEGER ; n3: INTEGER ; n4: INTEGER ; n5: INTEGER)
			-- Initialization for `Current'.
		do
			row_count := rows+1
			col_count := cols+1
			g_threshold := n1
			f_threshold:= n2
			c_threshold := n3
			i_threshold := n4
			p_threshold := n5
			create grid.make_filled("_", row_count, col_count)

			-- Entity initialization
			starfighter.make (row_count)
			create {ARRAYED_LIST[PROJECTILE]} projectiles.make (10)
			create {ARRAYED_LIST[ENEMY]} enemies.make (10)
		end

	reset
		do
			grid.make_filled("_", row_count, col_count)
			make_empty
		end

feature -- GRID attributes

	-- Initial state with welcoming message
	grid: ARRAY2[STRING]
	row_count: INTEGER
	col_count: INTEGER

	-- Game specifications;
	g_threshold: INTEGER_32
	f_threshold: INTEGER_32
	c_threshold: INTEGER_32
	i_threshold: INTEGER_32
	p_threshold: INTEGER_32

	-- Entities (starfighter, enemies, projectiles)
	starfighter: STARFIGHTER
	projectiles: LIST[PROJECTILE]
	enemies: LIST[ENEMY]

	-- collision handler
	collision_handler: COLLISIONS

feature -- enumeration of game-wide constants

	standard_movement: INTEGER
	spread_movement_right: INTEGER
	spread_movement_top_right: INTEGER
	spread_movement_bottom_right: INTEGER
	snipe_movement: INTEGER
	rocket_movement: INTEGER
	splitter_movement: INTEGER
	enemy_left_movement: INTEGER

feature -- mutators

	apply_entities_locs
		do
			grid.make_filled("_", row_count, col_count)
			-- pply starfighter loc
			if not starfighter.is_dead then
				grid[starfighter.row_loc, starfighter.col_loc] := "S"
			else
				grid[starfighter.row_loc, starfighter.col_loc] := "X"
			end

			-- apply projectiles locs
			across
				projectiles is projectile
			loop
				if projectile.is_on_grid and not projectile.is_dead then
					if projectile.is_friendly then
						grid[projectile.row_loc, projectile.col_loc] := "*"
					else
						grid[projectile.row_loc, projectile.col_loc] := "<"
					end
				end
			end

			-- apply enemies locs
			across
				enemies is enemy
			loop
				if enemy.is_on_grid and not enemy.is_dead then
					grid[enemy.row_loc, enemy.col_loc] := enemy.type
				end
			end

		end

	apply_grid_dust
		local
			distance: INTEGER
		do
			across
				1 |..| row_count is row
			loop
				across
					1 |..| col_count is col
				loop
					distance := calculate_distance (starfighter.row_loc, starfighter.col_loc, row, col)
					if distance > starfighter.vision then
						grid[row, col] := "?"
					end
				end
			end
		end

	clear_grid_dust
		do
			across
				1 |..| row_count is row
			loop
				across
					1 |..| col_count is col
				loop
					if grid[row, col] ~ "?" then
						grid[row, col] := "_"
					end
				end
			end
		end

	calculate_distance (locX0: INTEGER ; locY0: INTEGER ; locX1: INTEGER ; locY1: INTEGER): INTEGER
		do
			Result := absolute_value(locX1-locX0) + absolute_value(locY1-locY0)
		end

feature -- context features

	-- translating grid row indices to relevant row letter (first row is already used for column numbering)
	row_nb_to_letter(row_nb: INTEGER): STRING
		require
			2 <= row_nb and row_nb <= 11
		do
			create Result.make_empty
			if row_nb = 2 then
				Result.append("A")
			elseif row_nb = 3 then
				Result.append("B")
			elseif row_nb = 4 then
				Result.append("C")
			elseif row_nb = 5 then
				Result.append("D")
			elseif row_nb = 6 then
				Result.append("E")
			elseif row_nb = 7 then
				Result.append("F")
			elseif row_nb = 8 then
				Result.append("G")
			elseif row_nb = 9 then
				Result.append("H")
			elseif row_nb = 10 then
				Result.append("I")
			elseif row_nb = 11 then
				Result.append("J")
			end
		end

	-- used to translate enumberation to the business logic
	letter_to_row_nb(letter: STRING): INTEGER
		require
			(letter ~ "A") or (letter ~ "B") or (letter ~ "C") or (letter ~ "D") or (letter ~ "E") or
			(letter ~ "F") or (letter ~ "G") or (letter ~ "H") or (letter ~ "I") or (letter ~ "J")
		do
			if letter ~ "A" then
				Result := 2
			elseif letter ~ "B" then
				Result := 3
			elseif letter ~ "C" then
				Result := 4
			elseif letter ~ "D" then
				Result := 5
			elseif letter ~ "E" then
				Result := 6
			elseif letter ~ "F" then
				Result := 7
			elseif letter ~ "G" then
				Result := 8
			elseif letter ~ "H" then
				Result := 9
			elseif letter ~ "I" then
				Result := 10
			elseif letter ~ "J" then
				Result := 11
			end
		end

	max_of_two_integers (int_1: INTEGER ; int_2: INTEGER): INTEGER
		do
			if int_1 > int_2 then
				Result := int_1
			else
				Result := int_2
			end
		end

	min_of_two_integers (int_1: INTEGER ; int_2: INTEGER): INTEGER
		do
			if int_1 < int_2 then
				Result := int_1
			else
				Result := int_2
			end
		end

	absolute_value (x: INTEGER): INTEGER
		do
			Result := x
			if x < 0 then
				Result := -x
			end
		end

	get_projectile_at (row_loc: INTEGER ; col_loc: INTEGER): detachable PROJECTILE
		do
			if (2 <= row_loc and row_loc <= row_count) and (2 <= col_loc and col_loc <= col_count) then
				across
					projectiles is projectile
				loop
					if (projectile.row_loc = row_loc) and (projectile.col_loc = col_loc) and (not projectile.is_dead) then
						Result := projectile
					end
				end
			end
		end

	get_enemy_at (row_loc: INTEGER ; col_loc: INTEGER): detachable ENEMY
		do
			if (2 <= row_loc and row_loc <= row_count) and (2 <= col_loc and col_loc <= col_count) then
				across
					enemies is enemy
				loop
					if (enemy.row_loc = row_loc) and (enemy.col_loc = col_loc) and (not enemy.is_dead)then
						Result := enemy
					end
				end
			end
		end

feature -- turn

	perform_phase_1
		local
			state_access: STATE_ACCESS
			state: STATE
			setup: SETUP
			setup_access: SETUP_ACCESS
		do
			setup := setup_access.m
			state := state_access.m
			across
				projectiles is projectile
			loop
				-- move projectiles
				if projectile.is_friendly then
					if projectile.is_on_grid and not projectile.is_dead then
						if not starfighter.is_dead then
							projectile.perform_move
						end
						state := state_access.m
						if projectile.is_on_grid and not projectile.is_dead then
							-- insert friendly projectile action debug string
							if setup.steps.at (1).selection_made = 5  then
								-- splitter weapon chosen, projectile stays still
								state.debug_string.insert_entry (state.debug_string.friendly_projectile_action_code, projectile.generate_friendly_splitter_projectile_action_debug_string)
							else
								-- non splitter weapon chosen, projectile moves
								state.debug_string.insert_entry (state.debug_string.friendly_projectile_action_code, projectile.generate_friendly_projectile_action_debug_string)
								if state.debug_string.friendly_projectile_action_delayed.count > 0 then
									state.debug_string.insert_entry (state.debug_string.friendly_projectile_action_code, state.debug_string.friendly_projectile_action_delayed)
									state.debug_string.friendly_projectile_action_delayed := ""
								end
							end

						elseif projectile.was_on_grid then
							-- Projectile escapeed board without dying
							state.debug_string.insert_entry (state.debug_string.friendly_projectile_action_code, projectile.generate_friendly_projectile_action_debug_string)
							if state.debug_string.friendly_projectile_action_delayed.count > 0 then
								state.debug_string.insert_entry (state.debug_string.friendly_projectile_action_code, state.debug_string.friendly_projectile_action_delayed)
								state.debug_string.friendly_projectile_action_delayed := ""
							end
						end
					end
				end
			end
		end

	perform_phase_2
		local
			state_access: STATE_ACCESS
			state: STATE
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			state := state_access.m
			war_grid := war_grid_access.m
			across
				projectiles is projectile
			loop
				if not projectile.is_friendly then
					if projectile.is_on_grid and not projectile.is_dead then
						if not starfighter.is_dead then
							projectile.perform_move
						end

						if projectile.is_on_grid and not projectile.is_dead then
							if not starfighter.is_dead then
								state.debug_string.insert_entry (state.debug_string.enemy_projectile_action_code, projectile.generate_enemy_projectile_move_action_debug_string)
							end

						elseif projectile.is_on_grid and projectile.is_dead then
							-- Projectile died while moving on grid
							state.debug_string.insert_entry (state.debug_string.enemy_projectile_action_code, projectile.generate_enemy_projectile_move_action_debug_string)

						elseif projectile.was_on_grid and not starfighter.is_dead then
							-- Projectile escapeed board without dying
							state.debug_string.insert_entry (state.debug_string.enemy_projectile_action_code, projectile.generate_enemy_projectile_move_action_debug_string)
						end

						if state.debug_string.enemy_projectile_action_delayed.count > 0 then
							state.debug_string.insert_entry (state.debug_string.enemy_projectile_action_code, state.debug_string.enemy_projectile_action_delayed)
							state.debug_string.enemy_projectile_action_delayed := ""
						end
					end
				end
			end
		end

	perform_phase_3 (last_command: STRING ; tgt_row: INTEGER ; tgt_col: INTEGER)
		local
			state_access: STATE_ACCESS
			state_header: STATE
			setup_access: SETUP_ACCESS
			setup: SETUP
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			spawned_projectiles: LIST[PROJECTILE]
		do
			if not starfighter.is_dead then
				create {ARRAYED_LIST[PROJECTILE]} spawned_projectiles.make (10)
				state_header := state_access.m
				setup := setup_access.m
				war_grid := war_grid_access.m
				if last_command ~ "pass" then
					-- apply regeneration twice
					starfighter.apply_regeneration
					starfighter.apply_regeneration

					-- Add pass action to starfighter debug report
					state_header.debug_string.insert_entry (state_header.debug_string.starfighter_action_code, starfighter.generate_starfighter_pass_action_debug_string)

				elseif last_command ~ "move" then
					-- apply regeneration
					starfighter.apply_regeneration
					starfighter.apply_move (tgt_row, tgt_col)

					-- Add move action to starfighter debug report
					state_header.debug_string.insert_entry (state_header.debug_string.starfighter_action_code, starfighter.generate_starfighter_move_action_debug_string)
					if state_header.debug_string.starfighter_action_delayed.count > 0 then
						state_header.debug_string.insert_entry (state_header.debug_string.starfighter_action_code, state_header.debug_string.starfighter_action_delayed)
						state_header.debug_string.starfighter_action_delayed := ""
					end

				elseif last_command ~ "fire" then
					-- apply regeneration
					starfighter.apply_regeneration
					-- subtract the cost of firing
					if starfighter.projectile_cost_unites ~ "energy" then
						starfighter.energy := starfighter.energy - starfighter.projectile_cost
					elseif starfighter.projectile_cost_unites ~ "health" then
						starfighter.health := starfighter.health - starfighter.projectile_cost
					end

					-- spawn friendly projectile based on weapon chosen
					if setup.steps.at (1).selection_made = 1 then
						-- Standard weapon chosen
						spawned_projectiles := spawn_friendly_standard_projectile
					elseif setup.steps.at (1).selection_made = 2 then
						-- Spread weapon chosen
						spawned_projectiles := spawn_friendly_spread_projectile
					elseif setup.steps.at (1).selection_made = 3 then
						-- Snipe weapon chosen
						spawned_projectiles := spawn_friendly_snipe_projectile
					elseif setup.steps.at (1).selection_made = 4 then
						-- Rocket weapon chosen
						spawned_projectiles := spawn_friendly_rocket_projectile
					elseif setup.steps.at (1).selection_made = 5 then
						-- Splitter weapon chosen
						spawned_projectiles := spawn_friendly_splitter_projectile
					end

					-- Add fire action to starfighter debug report
					state_header.debug_string.insert_entry (state_header.debug_string.starfighter_action_code,
					starfighter.generate_starfighter_fire_action_debug_string (spawned_projectiles))

					-- add delayed report
					if state_header.debug_string.starfighter_action_delayed.count > 0 then
						state_header.debug_string.insert_entry (state_header.debug_string.starfighter_action_code, state_header.debug_string.starfighter_action_delayed)
						state_header.debug_string.starfighter_action_delayed := ""
					end

				elseif last_command ~ "special" then
					setup.last_step.inact_power
					-- add special action debug report
					state_header.debug_string.insert_entry (state_header.debug_string.starfighter_action_code,
							war_grid.starfighter.generate_starfighter_special_action_debug_string (setup.last_step.selection_made))
					--attach delayed actions
					if state_header.debug_string.starfighter_action_delayed.count > 0 then
						state_header.debug_string.insert_entry (state_header.debug_string.starfighter_action_code,
							state_header.debug_string.starfighter_action_delayed)
					end
				end
			end
		end

	perform_phase_4
		do
			if not starfighter.is_dead then
				across
					enemies is enemy
				loop
					enemy.update_seen_by_starfighter
					enemy.update_can_see_starfighter
				end
			end
		end

	perform_phase_5 (last_command: STRING)
		local
			enemies_still_needing_to_act: LIST[ENEMY]
			enemy_turn_ended: BOOLEAN
		do
			if not starfighter.is_dead then
				create {ARRAYED_LIST[ENEMY]} enemies_still_needing_to_act.make (10)
				-- Preempt all enemies
				across
					enemies is enemy
				loop
					if not starfighter.is_dead then
						if enemy.is_on_grid and not enemy.is_dead then
							if last_command ~ "pass" then
								enemy_turn_ended := enemy.preempt_action (true, false, false, false)
							elseif last_command ~ "fire" then
								enemy_turn_ended := enemy.preempt_action (false, true, false, false)
							elseif last_command ~ "move" then
								enemy_turn_ended := enemy.preempt_action (false, false, true, false)
							elseif last_command ~ "special" then
								enemy_turn_ended := enemy.preempt_action (false, false, false, true)
							end

							if (enemy.is_on_grid) and (not enemy.is_dead) and (not enemy_turn_ended) then
								enemies_still_needing_to_act.force (enemy)
							end
						end
					end
				end

				-- Let enemies whose turns did not end act, if the starfighter did not die during preemption
				across
					enemies_still_needing_to_act is acting_enemy
				loop
					if not starfighter.is_dead then
						acting_enemy.act
					end
				end
			end
		end

	perform_phase_6
		do
			across
				enemies is enemy
			loop
				if not starfighter.is_dead then
					perform_phase_4
				end
				enemy.report_enemy
			end
		end

	perform_phase_7
		local
			random_geerator_access: RANDOM_GENERATOR_ACCESS
			rng_row: INTEGER
			rng_enemy: INTEGER
			war_grid: WAR_GRID
			war_grid_access: WAR_GRID_ACCESS
			state: STATE
			state_access: STATE_ACCESS
		do
			state := state_access.m
			war_grid := war_grid_access.m
			if not starfighter.is_dead then
				rng_row := random_geerator_access.rchoose (1, row_count-1) + 1
				rng_enemy := random_geerator_access.rchoose (1, 100)

				if 1 <= rng_enemy and rng_enemy < g_threshold then
					spawn_enemy ("G", rng_row, war_grid.col_count, state.debug_string.natural_enemy_spawn_code, true)
				elseif g_threshold <= rng_enemy and rng_enemy < f_threshold then
					spawn_enemy ("F", rng_row, war_grid.col_count, state.debug_string.natural_enemy_spawn_code, true)
				elseif f_threshold <= rng_enemy and rng_enemy < c_threshold then
					spawn_enemy ("C", rng_row, war_grid.col_count, state.debug_string.natural_enemy_spawn_code, true)
				elseif c_threshold <= rng_enemy and rng_enemy < i_threshold then
					spawn_enemy ("I", rng_row, war_grid.col_count, state.debug_string.natural_enemy_spawn_code, true)
				elseif i_threshold <= rng_enemy and rng_enemy < p_threshold then
					spawn_enemy ("P", rng_row, war_grid.col_count, state.debug_string.natural_enemy_spawn_code, true)
				end
			end

			-- report the projectile that are still live after the starfighter's move
			report_live_projectiles
		end

feature -- helper functions for friendly projectiles spawned

	spawn_friendly_standard_projectile: LIST[PROJECTILE]
		local
			state_access: STATE_ACCESS
			state: STATE
		do
			state := state_access.m
			create {ARRAYED_LIST[PROJECTILE]} Result.make (10)

			-- create projectile
			Result.force (create {PROJECTILE}.make ((projectiles.count+1) * -1, true, starfighter.row_loc, starfighter.col_loc+1,
													5, standard_movement, starfighter.projectile_damage))

			-- insert projectile into projectiles list
			projectiles.force (Result.at (1))

			-- check for possible collisions
			collision_handler.handle_friendly_projectile_initiated_collision (state.debug_string.starfighter_action_code_delayed, Result.at (1))
		end

	spawn_friendly_spread_projectile: LIST[PROJECTILE]
		local
			state_access: STATE_ACCESS
			state: STATE
		do
			create {ARRAYED_LIST[PROJECTILE]} Result.make (10)
			state := state_access.m

			-- create projectile and add them to projectiles list
			Result.force (create {PROJECTILE}.make ((projectiles.count+1) * -1, true, starfighter.row_loc-1, starfighter.col_loc+1,
													1, spread_movement_top_right, starfighter.projectile_damage)) -- top right
			projectiles.force (Result.at (1))
			-- check for possible collisions
			collision_handler.handle_friendly_projectile_initiated_collision (state.debug_string.starfighter_action_code_delayed, Result.at (1))



			Result.force (create {PROJECTILE}.make ((projectiles.count+1) * -1, true, starfighter.row_loc, starfighter.col_loc+1,
													1, spread_movement_right, starfighter.projectile_damage)) -- right
			projectiles.force (Result.at (2))
			-- check for possible collisions
			collision_handler.handle_friendly_projectile_initiated_collision (state.debug_string.starfighter_action_code_delayed, Result.at (2))



			Result.force (create {PROJECTILE}.make ((projectiles.count+1) * -1, true, starfighter.row_loc+1, starfighter.col_loc+1,
													1, spread_movement_bottom_right, starfighter.projectile_damage)) -- top right
			projectiles.force (Result.at (3))
			-- check for possible collisions
			collision_handler.handle_friendly_projectile_initiated_collision (state.debug_string.starfighter_action_code_delayed, Result.at (3))
		end

	spawn_friendly_snipe_projectile: LIST[PROJECTILE]
		local
			state_access: STATE_ACCESS
			state: STATE
		do
			create {ARRAYED_LIST[PROJECTILE]} Result.make (10)
			state := state_access.m

			-- create projectile
			Result.force (create {PROJECTILE}.make ((projectiles.count+1) * -1, true, starfighter.row_loc, starfighter.col_loc+1,
													8, snipe_movement, starfighter.projectile_damage))


			-- insert projectile into projectiles list
			projectiles.force (Result.at (1))
			-- check for possible collisions
			collision_handler.handle_friendly_projectile_initiated_collision (state.debug_string.starfighter_action_code_delayed, Result.at (1))
		end

	spawn_friendly_rocket_projectile: LIST[PROJECTILE]
		local
			state_access: STATE_ACCESS
			state: STATE
		do
			create {ARRAYED_LIST[PROJECTILE]} Result.make (10)
			state := state_access.m

			-- create projectile and add them to projectiles list
			Result.force (create {PROJECTILE}.make ((projectiles.count+1) * -1, true, starfighter.row_loc-1, starfighter.col_loc-1,
													1, rocket_movement, starfighter.projectile_damage)) -- top right
			projectiles.force (Result.at (1))
			-- check for possible collisions
			collision_handler.handle_friendly_projectile_initiated_collision (state.debug_string.starfighter_action_code_delayed, Result.at (1))



			Result.force (create {PROJECTILE}.make ((projectiles.count+1) * -1, true, starfighter.row_loc+1, starfighter.col_loc-1,
													1, rocket_movement, starfighter.projectile_damage)) -- top right
			projectiles.force (Result.at (2))
			-- check for possible collisions
			collision_handler.handle_friendly_projectile_initiated_collision (state.debug_string.starfighter_action_code_delayed, Result.at (2))
		end

	spawn_friendly_splitter_projectile: LIST[PROJECTILE]
		local
			state_access: STATE_ACCESS
			state: STATE
		do
			create {ARRAYED_LIST[PROJECTILE]} Result.make (10)
			state := state_access.m

			-- create projectile
			Result.force (create {PROJECTILE}.make ((projectiles.count+1) * -1, true, starfighter.row_loc, starfighter.col_loc+1,
													0, splitter_movement, starfighter.projectile_damage))

			-- insert projectile into projectiles list
			projectiles.force (Result.at (1))
			-- check for possible collisions
			collision_handler.handle_friendly_projectile_initiated_collision (state.debug_string.starfighter_action_code_delayed, Result.at (1))
		end

feature -- helper functions for enemies spawned

	spawn_enemy (enemy_type_letter: STRING ; row_loc: INTEGER ; col_loc: INTEGER ; action_code: INTEGER ; should_report_enemy: BOOLEAN)
		local
			state_access: STATE_ACCESS
			state: STATE
			spawned_enemy: ENEMY
			enemy_eradicated_at_spawn: BOOLEAN
		do
			state := state_access.m

			-- create enemy
			create {ENEMY_GRUNT} spawned_enemy.make (enemies.count+1, row_loc, col_loc) -- default is grunt
			if enemy_type_letter ~ "F" then
				create {ENEMY_FIGHTER} spawned_enemy.make (enemies.count+1, row_loc, col_loc)
			elseif enemy_type_letter ~ "C" then
				create {ENEMY_CARRIER} spawned_enemy.make (enemies.count+1, row_loc, col_loc)
			elseif enemy_type_letter ~ "I" then
				create {ENEMY_INTERCEPTOR} spawned_enemy.make (enemies.count+1, row_loc, col_loc)
			elseif enemy_type_letter ~ "P" then
				create {ENEMY_PYLON} spawned_enemy.make (enemies.count+1, row_loc, col_loc)
			end

			-- check for possible collisions
			enemy_eradicated_at_spawn := run_enemy_spawn_collision_scenarios_at_loc (spawned_enemy)

			if not enemy_eradicated_at_spawn then
				-- insert enemy into enemies list
				enemies.force (spawned_enemy)

				if should_report_enemy then
					-- insert enemy debug string
					spawned_enemy.report_enemy
				end

				-- insert enemy natural spawn debug strig
				spawned_enemy.report_enemy_spawn (action_code)
			end
		end

	-- returns true if enemy is eradicated (no id to assign), false otherwise
	run_enemy_spawn_collision_scenarios_at_loc (enemy: ENEMY): BOOLEAN
		local
			state_access: STATE_ACCESS
			state: STATE
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			Result := false
			state := state_access.m
			war_grid := war_grid_access.m
			-- check collisions with projectiles
			across
				projectiles is projectile
			loop
				if (projectile.row_loc = enemy.row_loc)
					and
					(projectile.col_loc = enemy.col_loc)
					and
					(not projectile.is_dead) then
					if projectile.is_friendly then
						projectile.kill (enemy.id, enemy.get_enemy_name)
						enemy.health := enemy.health - war_grid.max_of_two_integers (projectile.damage - enemy.armour, 0)
						if enemy.health = 0 then
							enemy.kill (projectile.id, "Projectile")
						end
						-- state.debug_string.insert_entry (state.debug_string.enemy_action_code_delayed,
						--	enemy.generate_collision_with_projectile_debug_string(projectile.is_friendly, projectile.id, projectile.damage - enemy.armour))
					else
						projectile.kill (enemy.id, enemy.get_enemy_name)
						enemy.health := war_grid.min_of_two_integers (enemy.health + projectile.damage, enemy.max_health)
					end
				end
			end

			-- check collisions with enemies
			across
				enemies is some_enemy
			loop
				if (some_enemy.row_loc = enemy.row_loc)
					and
					(some_enemy.col_loc = enemy.col_loc)
					and
					(not some_enemy.is_dead) then
					Result := true
				end
			end

			-- check collisions with starfighter
			if (starfighter.row_loc = enemy.row_loc)
				and
				(starfighter.col_loc = enemy.col_loc) then
					enemy.kill (war_grid.starfighter.id, "Starfighter")
					war_grid.starfighter.health := war_grid.starfighter.health - enemy.health
					if war_grid.starfighter.health <= 0 then
						-- starfighter died, game over
						war_grid.starfighter.kill
					else
						-- starfighter still alive, nothing else to do
					end
			end
		end

feature {NONE} -- general helper functions

	report_live_projectiles
		local
			state_access: STATE_ACCESS
			state: STATE
		do
			state := state_access.m
			across
				projectiles is projectile
			loop
				if (not projectile.is_dead) and projectile.is_on_grid then
					state.debug_string.insert_entry (state.debug_string.projetile_code, projectile.generate_projectile_debug_string)
				end
			end

		end

feature -- Queries

	out : STRING
		do
			create Result.make_empty
			across
				1 |..| row_count is r
			loop
				across
					1 |..| col_count is c
				loop
					if r = 1 then
						if c = 1 then
							Result.append ("      ")
							Result.append (c.out)
						elseif (c < 10) and (c < col_count) then
							Result.append ("  ")
							Result.append (c.out)
						elseif (c >= 10) and (c < col_count) then
							Result.append (" ")
							Result.append (c.out)
						end

					else
						if c = 1 then
							Result.append ("    ")
							Result.append (row_nb_to_letter(r))
							Result.append (" ")
						else
							Result.append (grid[r, c])
							if c < col_count then
							Result.append ("  ")
							end
						end
					end
				end
				if r < row_count then
					Result.append ("%N")
				end
			end
		end

end

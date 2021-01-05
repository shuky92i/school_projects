note
	description: "Summary description for {ENEMY}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	ENEMY

feature -- init

	make (p_id: INTEGER ; p_row_loc: INTEGER ; p_col_loc: INTEGER)
		deferred
		end

feature -- attributes

	id: INTEGER
	row_loc: INTEGER
	col_loc: INTEGER assign set_col_loc

	health: INTEGER assign set_health
	max_health: INTEGER
	regen_health: INTEGER
	armour: INTEGER
	vision: INTEGER
	seen_by_starfighter: BOOLEAN
	can_see_starfighter: BOOLEAN

	enemy_type: INTEGER

	is_dead: BOOLEAN
	killed_by_entity_name: STRING
	killed_by_entity_id: INTEGER
	enemy_collision_with_enemy: BOOLEAN

	-- The location where the enemy was spawned
	prev_row_loc: INTEGER
	prev_col_loc: INTEGER

feature -- mutators

	set_loc (new_row_loc: INTEGER ; new_col_loc: INTEGER)
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			row_loc := new_row_loc
			col_loc := new_col_loc
		end

	set_col_loc (p_col_loc: INTEGER)
		do
			col_loc := p_col_loc
		end

	apply_regeneration
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			if health < max_health then
				health := war_grid.min_of_two_integers (max_health, health + regen_health)
			end
		end

	set_health (p_health: INTEGER)
		do
			health := p_health
		end

	update_seen_by_starfighter
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			if war_grid.calculate_distance (row_loc, col_loc, war_grid.starfighter.row_loc, war_grid.starfighter.col_loc) <=
				war_grid.starfighter.vision then
				seen_by_starfighter := true
			else
				seen_by_starfighter := false
			end

		end

	update_can_see_starfighter
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			if war_grid.calculate_distance (row_loc, col_loc, war_grid.starfighter.row_loc, war_grid.starfighter.col_loc) <= vision then
				can_see_starfighter := true
			else
				can_see_starfighter := false
			end

		end

	kill (p_killed_by_enity_id: INTEGER ; p_killed_by_entity_name: STRING)
		local
			state_access: STATE_ACCESS
			state: STATE
		do
			state := state_access.m
			is_dead := true
			killed_by_entity_id := p_killed_by_enity_id
			killed_by_entity_name := p_killed_by_entity_name
			handle_scoring
		end

	handle_scoring
		deferred
		end

	sync_prev_loc_to_curr_loc
		do
			prev_row_loc := row_loc
			prev_col_loc := col_loc
		end

feature -- preemptions and actions

	-- return true if enemy's turn ended
	preempt_action (pass: BOOLEAN ; fire: BOOLEAN ; move: BOOLEAN ; special: BOOLEAN): BOOLEAN
		deferred
		end

	act
		deferred
		end

feature {NONE} -- preemption and act helper functions

	perform_move (move_steps_per_turn: INTEGER)
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			state: STATE
			state_access: STATE_ACCESS
			collision_check_result: INTEGER
		do
			war_grid := war_grid_access.m
			state := state_access.m
			sync_prev_loc_to_curr_loc

			across
				1 |..| move_steps_per_turn is step
			loop
				if (not is_dead) and is_on_grid and
				not (collision_check_result = war_grid.collision_handler.r_enemy_requested_abortion) and
				not (collision_check_result = war_grid.collision_handler.r_enemy_died) then
					-- Check collision cases
					set_loc (row_loc, col_loc-1)
					collision_check_result := war_grid.collision_handler.handle_enemy_initiated_collision (state.debug_string.enemy_action_code_delayed, Current)
				end
			end

			if collision_check_result = war_grid.collision_handler.r_enemy_requested_abortion then
				set_loc (row_loc, col_loc + 1)  -- retreat by one
			end
		end

	spawn_projectile (move_steps_per_turn: INTEGER ; projectile_damage: INTEGER): LIST[PROJECTILE]
		local
			state_access: STATE_ACCESS
			state: STATE
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			spawned_projectile: PROJECTILE
		do
			war_grid := war_grid_access.m
			create {ARRAYED_LIST[PROJECTILE]} Result.make (10)
			state := state_access.m

			-- create projectile
		 	create spawned_projectile.make ((war_grid.projectiles.count+1) * -1, false, row_loc, col_loc-1,
													move_steps_per_turn, war_grid.enemy_left_movement, projectile_damage)

			-- Add projectile to result for reporting purposes
			Result.force (spawned_projectile)

			-- insert projectile into projectiles list
			war_grid.projectiles.force (Result.at (1))

			-- check for possible collisions
			war_grid.collision_handler.handle_enemy_projectile_initiated_collision (state.debug_string.enemy_action_code_delayed, spawned_projectile)
		end

	perform_act_move_spawn_projectile_if_applicable (number_of_moves: INTEGER ; move_steps_per_turn: INTEGER ; projectile_damage: INTEGER)
		local
			state_access: STATE_ACCESS
			state: STATE
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			spawned_projectiles: LIST[PROJECTILE]
		do
			state := state_access.m
			war_grid := war_grid_access.m
			perform_move (number_of_moves)
			create {ARRAYED_LIST[PROJECTILE]} spawned_projectiles.make (10)

			-- Report enemy
			report_enemy_action_moving
			if state.debug_string.enemy_action_delayed.count > 0 then
				state.debug_string.insert_entry (state.debug_string.enemy_action_code, state.debug_string.enemy_action_delayed)
				state.debug_string.enemy_action_delayed := ""
			end

			if is_on_grid and not is_dead then
				-- Enemy survives move
				spawned_projectiles := spawn_projectile (move_steps_per_turn, projectile_damage)
				-- check for possible collisions
				report_enemy_action_firing_projectile (spawned_projectiles)
				-- add delayed string
				if state.debug_string.enemy_action_delayed.count > 0 then
					state.debug_string.insert_entry (state.debug_string.enemy_action_code, state.debug_string.enemy_action_delayed)
					state.debug_string.enemy_action_delayed := ""
				end
			end
		end

feature --Report events

	report_enemy
		local
			state_access: STATE_ACCESS
			state_header: STATE
		do
			if is_on_grid and not is_dead then
				state_header := state_access.m
				state_header.debug_string.insert_entry (state_header.debug_string.enemy_code, generate_enemy_debug_string)
			end
		end

	report_enemy_action_firing_projectile (spawned_projectiles: LIST[PROJECTILE])
		local
			state_access: STATE_ACCESS
			state_header: STATE
		do
			state_header := state_access.m
			state_header.debug_string.insert_entry (state_header.debug_string.enemy_action_code, generate_enemy_action_firing_projectile_debug_string (spawned_projectiles))
		end

	report_enemy_action_moving
		local
			state_access: STATE_ACCESS
			state_header: STATE
		do
			state_header := state_access.m
			state_header.debug_string.insert_entry (state_header.debug_string.enemy_action_code, generate_enemy_action_moving)
		end

	report_enemy_spawn (action_code: INTEGER)
		local
			state_access: STATE_ACCESS
			state_header: STATE
		do
			state_header := state_access.m
			if action_code = state_header.debug_string.natural_enemy_spawn_code then
				state_header.debug_string.insert_entry (action_code, gnerate_natural_enemy_spawn_debug_string)
			else
				state_header.debug_string.insert_entry (action_code, gnerate_artificial_enemy_spawn_debug_string)
			end

		end

	report_enemy_gains_total_health (gain_value: INTEGER)
		local
			state_access: STATE_ACCESS
			state_header: STATE
		do
			state_header := state_access.m
			state_header.debug_string.insert_entry (state_header.debug_string.enemy_action_code, generate_enemy_gains_total_health_debug_string (gain_value))
		end

	get_enemy_name: STRING
		do
			create Result.make_empty
			if type ~ "G" then
				Result := "Grunt"
			elseif type ~ "F" then
				Result := "Fighter"
			elseif type ~ "C" then
				Result := "Carrier"
			elseif type ~ "I" then
				Result := "Interceptor"
			elseif type ~ "P" then
				Result := "Pylon"
			end
		end

feature --debug string generation functions

	generate_enemy_debug_string: STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("    [")
			Result.append (id.out)
			Result.append (",")
			Result.append (type)
			Result.append ("]->health:")
			Result.append (health.out)
			Result.append ("/")
			Result.append (max_health.out)
			Result.append (", Regen:")
			Result.append (regen_health.out)
			Result.append (", Armour:")
			Result.append (armour.out)
			Result.append (", Vision:")
			Result.append (vision.out)
			Result.append (", seen_by_Starfighter:")
			if seen_by_starfighter then
				Result.append ("T")
			else
				Result.append ("F")
			end
			Result.append (", can_see_Starfighter:")
			if can_see_starfighter then
				Result.append ("T")
			else
				Result.append ("F")
			end
			Result.append (", location:[")
			Result.append (war_grid.row_nb_to_letter (row_loc))
			Result.append (",")
			Result.append ((col_loc-1).out)
			Result.append ("]")
		end

	generate_enemy_action_firing_projectile_debug_string (spawned_projectiles: LIST[PROJECTILE]): STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("      A enemy projectile(id:")
			Result.append (spawned_projectiles.at (1).id.out)
			Result.append (") spawns at location ")
			if spawned_projectiles.at (1).is_on_grid then
				Result.append ("[")
				Result.append (war_grid.row_nb_to_letter (spawned_projectiles.at (1).row_loc))
				Result.append (",")
				Result.append ((spawned_projectiles.at (1).col_loc-1).out)
				Result.append ("].")
			else
				Result.append ("out of board.")
			end

		end

	generate_enemy_action_moving: STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("    A ")
			Result.append (get_enemy_name)
			Result.append ("(id:")
			Result.append (id.out)
			Result.append (") ")

			if (prev_row_loc = row_loc) and (prev_col_loc = col_loc) then
				Result.append ("stays at: [")
				Result.append (war_grid.row_nb_to_letter (row_loc))
				Result.append (",")
				Result.append ((col_loc-1).out)
				Result.append ("]")
			else
				Result.append ("moves: [")
				Result.append (war_grid.row_nb_to_letter (prev_row_loc))
				Result.append (",")
				Result.append ((prev_col_loc-1).out)
				Result.append ("] -> ")
				if is_on_grid then
					Result.append ("[")
					Result.append (war_grid.row_nb_to_letter (row_loc))
					Result.append (",")
					Result.append ((col_loc-1).out)
					Result.append ("]")
				else
					Result.append ("out of board")
				end
			end
		end

	generate_enemy_death_debug_string: STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("      The ")
			Result.append (get_enemy_name)
			Result.append (" at location [")
			Result.append (war_grid.row_nb_to_letter (row_loc))
			Result.append (",")
			Result.append ((col_loc-1).out)
			Result.append ("] has been destroyed.")
		end

	gnerate_natural_enemy_spawn_debug_string: STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("    A ")
			Result.append (get_enemy_name)
			Result.append ("(id:")
			Result.append (id.out)
			Result.append (") spawns at location [")
			Result.append (war_grid.row_nb_to_letter (row_loc))
			Result.append (",")
			Result.append ((col_loc-1).out)
			Result.append ("].")
		end

	gnerate_artificial_enemy_spawn_debug_string: STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("      A ")
			Result.append (get_enemy_name)
			Result.append ("(id:")
			Result.append (id.out)
			Result.append (") spawns at location [")
			Result.append (war_grid.row_nb_to_letter (row_loc))
			Result.append (",")
			Result.append ((col_loc-1).out)
			Result.append ("].")
		end

	generate_enemy_gains_total_health_debug_string (gain_value: INTEGER): STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("    A ")
			Result.append (get_enemy_name)
			Result.append ("(id:")
			Result.append (id.out)
			Result.append (") gains ")
			Result.append (gain_value.out)
			Result.append (" total health.")
		end

feature -- queries

	-- If enemy is on board but dead, it's considered not on board.
	-- If enemy is on board and alive, it's opn board
	-- If enemy is not on board, it's not on board tautologically
	is_on_grid: BOOLEAN
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			Result := false
				war_grid := war_grid_access.m
				if (2 <= row_loc and row_loc <= war_grid.row_count)
					and
					(2 <= col_loc and col_loc <= war_grid.col_count)
					then
						Result := true
				end
		end

	type: STRING
		do
			create Result.make_empty
			if enemy_type = 1 then
				Result := "G"
			elseif enemy_type = 2 then
				Result := "F"
			elseif enemy_type = 3 then
				Result := "C"
			elseif enemy_type = 4 then
				Result := "I"
			elseif enemy_type = 5 then
				Result := "P"
			end
		end

end

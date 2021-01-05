note
	description: "Summary description for {PROJECTILE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	PROJECTILE

create
	make

feature -- initialization

	make(p_id: INTEGER ; p_is_friendly: BOOLEAN ; p_row_loc: INTEGER ; p_col_loc: INTEGER ;
			 p_move_steps_per_turn: INTEGER ; p_move_type: INTEGER ; p_damage: INTEGER)
		do
			id := p_id
			row_loc := p_row_loc
			col_loc := p_col_loc
			is_friendly := p_is_friendly

			prev_row_loc := row_loc
			prev_col_loc := col_loc

			move_steps_per_turn := p_move_steps_per_turn
			move_type := p_move_type
			damage := p_damage

			is_dead := false
			create killed_by_entity_name.make_empty
		end

feature -- attibutes

	-- The location where the projectile was spawned
	prev_row_loc: INTEGER
	prev_col_loc: INTEGER

	id: INTEGER
	row_loc: INTEGER
	col_loc: INTEGER
	is_friendly: BOOLEAN

	move_steps_per_turn: INTEGER
	move_type: INTEGER
	damage: INTEGER assign set_damage

	is_dead: BOOLEAN
	killed_by_entity_name: STRING
	killed_by_entity_id: INTEGER

feature -- mutators

	set_damage (p_damage: INTEGER)
		do
			damage := p_damage
		end

feature -- turn features

	perform_move
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			current_projectile_was_removed: BOOLEAN
			state: STATE
			state_access: STATE_ACCESS
		do
			sync_prev_loc_to_curr_loc
			war_grid := war_grid_access.m
			state := state_access.m
			current_projectile_was_removed := false

			-- move step by step
			if not (move_type = war_grid.snipe_movement) then
				across
					1 |..| move_steps_per_turn is step
				loop
					if (not is_dead) and is_on_grid then
						-- Check collision cases
						perform_dynamic_type_move
						-- report
						if is_friendly then
							war_grid.collision_handler.handle_friendly_projectile_initiated_collision (state.debug_string.friendly_projectile_action_code_delayed, Current)
						else
							war_grid.collision_handler.handle_enemy_projectile_initiated_collision (state.debug_string.enemy_projectile_action_code_delayed, Current)
						end
					end
				end
			end

			-- handle the snipe case teleporting 8 moves forward
			if move_type = war_grid.snipe_movement then
				set_loc (row_loc, col_loc+8) -- teleport right 8 steps
			end

			-- handle the rocket case doubling number of moves
			if move_type = war_grid.rocket_movement then
				move_steps_per_turn := move_steps_per_turn * 2 -- doubling move
			end

		end

feature --debug string generation functions

	generate_projectile_debug_string: STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("    [")
			Result.append (id.out)
			Result.append (",")
			if is_friendly then
				Result.append ("*")
			else
				Result.append ("<")
			end
			Result.append ("]->damage:")
			Result.append (damage.out)
			Result.append (", move:")
			Result.append (move_steps_per_turn.out)
			Result.append (", location:[")
			Result.append (war_grid.row_nb_to_letter (row_loc))
			Result.append (",")
			Result.append ((col_loc-1).out)
			Result.append ("]")
		end

	generate_friendly_projectile_action_debug_string: STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("    A friendly projectile(id:")
			Result.append (id.out)
			Result.append (") moves: [")
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

	generate_friendly_splitter_projectile_action_debug_string: STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("    A friendly projectile(id:")
			Result.append (id.out)
			Result.append (") stays at: [")
			Result.append (war_grid.row_nb_to_letter (prev_row_loc))
			Result.append (",")
			Result.append ((prev_col_loc-1).out)
			Result.append ("]")
		end

	generate_projectile_neutralized_debug_string: STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("      A projectile(id:")
			Result.append (id.out)
			Result.append (") at location [")
			Result.append (war_grid.row_nb_to_letter (row_loc))
			Result.append (",")
			Result.append ((col_loc-1).out)
			Result.append ("] has been neutralized.")
		end

	generate_enemy_projectile_move_action_debug_string: STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("    A enemy projectile(id:")
			Result.append (id.out)
			Result.append (") moves: [")
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

feature -- private helper functions

	perform_dynamic_type_move
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			if is_friendly then
				if move_type = war_grid.standard_movement then
				set_loc (row_loc, col_loc+1) -- move right 1 step
				elseif move_type = war_grid.spread_movement_top_right then
					set_loc (row_loc-1, col_loc+1) -- move top-right 1 step
				elseif move_type = war_grid.spread_movement_right then
					set_loc (row_loc, col_loc+1) -- move right 1 step
				elseif move_type = war_grid.spread_movement_bottom_right then
					set_loc (row_loc+1, col_loc+1) -- move bottom-right 1 step
				elseif move_type = war_grid.rocket_movement then
					set_loc (row_loc, col_loc+1) -- move right 1 step
				elseif move_type = war_grid.splitter_movement then
					-- Do nothing
				end
			else
				-- enemy projectile
				set_loc (row_loc, col_loc-1) -- move left 1 step
			end
		end

	set_loc (new_row_loc: INTEGER ; new_col_loc: INTEGER)
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			row_loc := new_row_loc
			col_loc := new_col_loc
		end

	sync_prev_loc_to_curr_loc
		do
			prev_row_loc := row_loc
			prev_col_loc := col_loc
		end

	kill (p_killed_by_enity_id: INTEGER ; p_killed_by_entity_name: STRING)
		do
			is_dead := true
			killed_by_entity_id := p_killed_by_enity_id
			killed_by_entity_name := p_killed_by_entity_name
		end

feature -- queries

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

	was_on_grid: BOOLEAN
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			Result := false
			war_grid := war_grid_access.m
			if (2 <= prev_row_loc and prev_row_loc <= war_grid.row_count)
				and
				(2 <= prev_col_loc and prev_col_loc <= war_grid.col_count)
				then
					Result := true
			end
		end

end

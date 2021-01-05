note
	description: "Summary description for {ENEMY_CARRIER}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	ENEMY_CARRIER

inherit
	ENEMY

create
	make

feature -- init

	make (p_id: INTEGER ; p_row_loc: INTEGER ; p_col_loc: INTEGER)
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			id := p_id
			row_loc := p_row_loc
			col_loc := p_col_loc

			health := 200
			max_health := health
			regen_health := 10
			armour := 15
			vision := 15

			enemy_type := 3
			is_dead := false

			prev_row_loc := row_loc
			prev_col_loc := col_loc

			update_can_see_starfighter
			update_seen_by_starfighter

			create killed_by_entity_name.make_empty
			enemy_collision_with_enemy := false
		end

feature -- preemptions and actions

	-- returns true if turn ended, false otherwise
	preempt_action (pass: BOOLEAN ; fire: BOOLEAN ; move: BOOLEAN ; special: BOOLEAN): BOOLEAN
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			state_access: STATE_ACCESS
			state: STATE
		do
			war_grid := war_grid_access.m
			state := state_access.m
			if is_on_grid then
				if special then
					regen_health := regen_health+10
					report_carrier_gaining_regen
					Result := false
				elseif pass then
					perform_move (2)
					-- Report enemy
					report_enemy_action_moving
					-- finish preemption
					if not is_dead and is_on_grid then
						war_grid.spawn_enemy ("I", row_loc-1, col_loc, state.debug_string.enemy_action_code_delayed, false) -- above carrier
						war_grid.spawn_enemy ("I", row_loc+1, col_loc, state.debug_string.enemy_action_code_delayed, false) -- below carrier
					end
					Result := true
				end
				if state.debug_string.enemy_action_delayed.count > 0 then
					state.debug_string.insert_entry (state.debug_string.enemy_action_code, state.debug_string.enemy_action_delayed)
					state.debug_string.enemy_action_delayed := ""
				end

			else
				Result := true
			end
		end

	act
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			state_access: STATE_ACCESS
			state: STATE
		do
			war_grid := war_grid_access.m
			state := state_access.m
			apply_regeneration
			if not can_see_starfighter then
				-- starfighter not seen
				perform_move (2)
				-- Report enemy
				report_enemy_action_moving
				if state.debug_string.enemy_action_delayed.count > 0 then
					state.debug_string.insert_entry (state.debug_string.enemy_action_code, state.debug_string.enemy_action_delayed)
					state.debug_string.enemy_action_delayed := ""
				end
			else
				-- starfighter seen
				perform_move (1)
				-- Report enemy
				report_enemy_action_moving
				-- finish preemption
				if not is_dead and is_on_grid then
					war_grid.spawn_enemy ("I", row_loc, col_loc-1, state.debug_string.enemy_action_code_delayed, false) -- left of carrier
				end
				if state.debug_string.enemy_action_delayed.count > 0 then
					state.debug_string.insert_entry (state.debug_string.enemy_action_code, state.debug_string.enemy_action_delayed)
					state.debug_string.enemy_action_delayed := ""
				end
			end
		end

	handle_scoring
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			score_transfered: BOOLEAN
		do
			war_grid := war_grid_access.m
			score_transfered := war_grid.starfighter.focus.add_score_item (3, war_grid.starfighter.focus.t_focus, 4, 3)
		end

feature {NONE} -- private helper functions

	report_carrier_gaining_regen
		local
			state_access: STATE_ACCESS
			state_header: STATE
		do
			state_header := state_access.m
			state_header.debug_string.insert_entry (state_header.debug_string.enemy_action_code_delayed,carrier_gaining_regen_debug_string)
		end

	carrier_gaining_regen_debug_string: STRING
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
			Result.append (") gains 10 regen.")
		end

end

note
	description: "Summary description for {ENEMY_INTERCEPTOR}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	ENEMY_INTERCEPTOR

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

			health := 50
			max_health := health
			regen_health := 0
			armour := 0
			vision := 5

			enemy_type := 4
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
				if fire then
					move_interceptor_vertically (row_loc, war_grid.starfighter.row_loc)
					-- Report enemy moving
					report_enemy_action_moving
					if state.debug_string.enemy_action_delayed.count > 0 then
						state.debug_string.insert_entry (state.debug_string.enemy_action_code, state.debug_string.enemy_action_delayed)
						state.debug_string.enemy_action_delayed := ""
					end
					Result := true
				end

			else
				Result := true
			end
		end

	act
		local
			state_access: STATE_ACCESS
			state: STATE
		do
			state := state_access.m
			apply_regeneration
			perform_move (3)
			-- Report enemy moving
			report_enemy_action_moving
			if state.debug_string.enemy_action_delayed.count > 0 then
				state.debug_string.insert_entry (state.debug_string.enemy_action_code, state.debug_string.enemy_action_delayed)
				state.debug_string.enemy_action_delayed := ""
			end
		end

	handle_scoring
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			score_transfered: BOOLEAN
		do
			war_grid := war_grid_access.m
			score_transfered := war_grid.starfighter.focus.add_score_item (1, war_grid.starfighter.focus.t_orb, -1, -1)
		end

feature {NONE} -- helper routines

	move_interceptor_vertically (orig_row: INTEGER ; tgt_row: INTEGER)
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			signed_step: INTEGER -- either 1 (going down) or -1 (going up)
			from_index: INTEGER
			to_index: INTEGER
			state_access: STATE_ACCESS
			state: STATE
			collision_check_result: INTEGER
		do
			war_grid := war_grid_access.m
			state := state_access.m
			sync_prev_loc_to_curr_loc

			if orig_row /= tgt_row then
				-- calculate step sign
				if orig_row < tgt_row then
					signed_step := 1
					from_index := orig_row
					to_index := tgt_row-1
				else
					signed_step := -1
					from_index := tgt_row
					to_index := orig_row-1
				end

				-- move starfighter vertically
				across
					from_index |..| to_index is step
				loop
					if (not is_dead) and not (collision_check_result = war_grid.collision_handler.r_enemy_requested_abortion) then
						set_loc (row_loc+signed_step, col_loc)
						collision_check_result := war_grid.collision_handler.handle_enemy_initiated_collision (state.debug_string.enemy_action_code_delayed, Current)
					end
				end

				if collision_check_result = war_grid.collision_handler.r_enemy_requested_abortion then
					set_loc (row_loc-signed_step, col_loc) -- retreat by one
				end
			end
		end

end

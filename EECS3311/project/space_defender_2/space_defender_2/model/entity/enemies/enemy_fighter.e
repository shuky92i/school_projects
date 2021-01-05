note
	description: "Summary description for {ENEMY_FIGHTER}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	ENEMY_FIGHTER

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

			health := 150
			max_health := health
			regen_health := 5
			armour := 10
			vision := 10

			enemy_type := 2
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
			state_access: STATE_ACCESS
			state: STATE
		do
			state := state_access.m
			if is_on_grid then
				if fire then
					armour := armour+1
					report_fighter_gaining_armour
					Result := false
				elseif pass then
					perform_act_move_spawn_projectile_if_applicable (6, 10, 100)
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
		do
			apply_regeneration
			if not can_see_starfighter then
				-- starfighter not seen
				perform_act_move_spawn_projectile_if_applicable (3, 3, 20)
			else
				-- starfighter seen
				perform_act_move_spawn_projectile_if_applicable (1, 6, 50)
			end
		end


	handle_scoring
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			score_transfered: BOOLEAN
		do
			war_grid := war_grid_access.m
			score_transfered := war_grid.starfighter.focus.add_score_item (3, war_grid.starfighter.focus.t_orb, -1, -1)
		end

feature {NONE} -- private helper functions

	report_fighter_gaining_armour
		local
			state_access: STATE_ACCESS
			state_header: STATE
		do
			state_header := state_access.m
			state_header.debug_string.insert_entry (state_header.debug_string.enemy_action_code_delayed,fighter_gaining_armour_debug_string)
		end

	fighter_gaining_armour_debug_string: STRING
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
			Result.append (") gains 1 armour.")
		end

end

note
	description: "Summary description for {ENEMY_PYLON}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	ENEMY_PYLON

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

			health := 300
			max_health := health
			regen_health := 0
			armour := 0
			vision := 5

			enemy_type := 5
			is_dead := false

			prev_row_loc := row_loc
			prev_col_loc := col_loc

			update_can_see_starfighter
			update_seen_by_starfighter

			create killed_by_entity_name.make_empty
			enemy_collision_with_enemy := false
		end

feature -- preemptions and actions

	preempt_action (pass: BOOLEAN ; fire: BOOLEAN ; move: BOOLEAN ; special: BOOLEAN): BOOLEAN
		do
			-- None
			Result := false
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

				-- Report enemy moving
				report_enemy_action_moving
				if state.debug_string.enemy_action_delayed.count > 0 then
					state.debug_string.insert_entry (state.debug_string.enemy_action_code, state.debug_string.enemy_action_delayed)
					state.debug_string.enemy_action_delayed := ""
				end

				if is_on_grid and not is_dead then
					-- Enemy survives move, revive enemies around pylon
					across
						war_grid.enemies is enemy
					loop
						if enemy.is_on_grid and not enemy.is_dead then
							if can_see_enemy (enemy) then
								enemy.health := war_grid.min_of_two_integers (enemy.health + 10, enemy.max_health)
								-- report pylon healling enemies
								state.debug_string.insert_entry (state.debug_string.enemy_action_code_delayed, pylon_healing_enemies_debug_string (enemy, 10))
							end
						end
					end

					-- add delayed string
					if state.debug_string.enemy_action_delayed.count > 0 then
						state.debug_string.insert_entry (state.debug_string.enemy_action_code, state.debug_string.enemy_action_delayed)
						state.debug_string.enemy_action_delayed := ""
					end
				end

			else
				-- starfighter seen
				perform_act_move_spawn_projectile_if_applicable (1, 2, 70)
			end
		end

	handle_scoring
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			score_transfered: BOOLEAN
		do
			war_grid := war_grid_access.m
			score_transfered := war_grid.starfighter.focus.add_score_item (1, war_grid.starfighter.focus.t_focus, 3, 2)
		end

feature {NONE} -- helepr fnctions

	can_see_enemy (enemy: ENEMY): BOOLEAN
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			if war_grid.calculate_distance (row_loc, col_loc, enemy.row_loc, enemy.col_loc) <= vision then
				Result := true
			else
				Result := false
			end

		end

	pylon_healing_enemies_debug_string (healed_enemy: ENEMY ; healed_damage: INTEGER): STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("      The Pylon heals ")
			Result.append (healed_enemy.get_enemy_name)
			Result.append ("(id:")
			Result.append (healed_enemy.id.out)
			Result.append (") at location [")
			Result.append (war_grid.row_nb_to_letter (healed_enemy.row_loc))
			Result.append (",")
			Result.append ((healed_enemy.col_loc-1).out)
			Result.append ("] for ")
			Result.append (healed_damage.out)
			Result.append (" damage.")
		end
end

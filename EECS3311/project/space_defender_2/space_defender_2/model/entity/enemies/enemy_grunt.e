note
	description: "Summary description for {ENEMY_GRUNT}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	ENEMY_GRUNT

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

			health := 100
			max_health := health
			regen_health := 1
			armour := 1
			vision := 5

			enemy_type := 1
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
		do
			if is_on_grid then
				if pass then
					health := health+10
					max_health := max_health+10
					report_enemy_gains_total_health (10)
				elseif special then
					health := health+20
					max_health := max_health+20
					report_enemy_gains_total_health (20)
				end
				Result := false
			else
				Result := true
			end
		end

	act
		do
			apply_regeneration
			if not can_see_starfighter then
				-- starfighter not seen
				perform_act_move_spawn_projectile_if_applicable (2, 4,15)
			else
				-- starfighter seen
				perform_act_move_spawn_projectile_if_applicable (4, 4, 15)
			end
		end

	handle_scoring
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			score_transfered: BOOLEAN
		do
			war_grid := war_grid_access.m
			score_transfered := war_grid.starfighter.focus.add_score_item (2, war_grid.starfighter.focus.t_orb, -1, -1)
		end

end

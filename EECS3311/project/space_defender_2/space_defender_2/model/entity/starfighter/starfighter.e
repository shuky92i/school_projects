note
	description: "Summary description for {STARFIGHTER}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	STARFIGHTER

inherit
	ANY
		redefine
			out
		end

create
	make

feature -- Initialization
	make (grid_row_count: INTEGER)
			-- Initialization for `Current'.
		do
			create projectile_cost_unites.make_empty
			create projectile_pattern.make_empty
			set_spawn_loc (grid_row_count)
			prev_row_loc := row_loc
			prev_col_loc := col_loc
			is_dead := false
			id := 0
			calculate_game_attributes
			create focus.make (0, 2, -1, true) -- The -1 indicates that this parameter is irrelavant in this specific case
										        -- The capacity is 2 because 1 is taken by the 0 score default orb and the capacity will increase
										        -- with every addition as indicated by the boolean flag
		end

feature -- attributes

	-- The location where the starfighter was spawned
	prev_row_loc: INTEGER
	prev_col_loc: INTEGER

	-- starfighter state, dead if collision happened with projectile
	is_dead: BOOLEAN

	-- game attributes
	row_loc: INTEGER
	col_loc: INTEGER
	id: INTEGER
	health: INTEGER assign set_health
	max_health: INTEGER
	energy: INTEGER assign set_energy
	max_energy: INTEGER
	regen_health: INTEGER
	regen_energy: INTEGER
	armour: INTEGER
	vision: INTEGER
	move: INTEGER
	move_cost: INTEGER
	projectile_pattern: STRING
	projectile_damage: INTEGER
	projectile_cost: INTEGER
	projectile_cost_unites: STRING -- "energy" or "health"
	power: POWER_SETUP
	focus: FOCUS


feature -- starfighter state mutators

	set_spawn_loc (p_grid_row_count: INTEGER)
		do
			row_loc := ((p_grid_row_count-1)/2).ceiling+1 -- we deduct 1 from grid_row_count then after ceiling we add it back
			col_loc := 2 -- Init at second colomn after letter
		end

	set_health (p_health: INTEGER)
		do
			health := p_health
		end

	set_energy (p_energy: INTEGER)
		do
			energy := p_energy
		end

	-- set starfighter location to new location and reset old location with "_"
	-- the new location is always valid as it's handled in main model - WAR_GRID
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

	-- A collision happened, mark the starfighter dead
	kill
		do
			health := 0
			is_dead := true
		end

feature -- turn features

	apply_regeneration
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			if health < max_health then
				health := war_grid.min_of_two_integers (max_health, health + regen_health)
			end
			if energy < max_energy then
				energy := war_grid.min_of_two_integers (max_energy, energy + regen_energy)
			end
		end

	apply_move (tgt_row: INTEGER ; tgt_col: INTEGER)
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			sync_prev_loc_to_curr_loc
			-- move vertically
			move_starfighter_vertically (row_loc, tgt_row)
			if not war_grid.starfighter.is_dead then
				-- move horizontally
				move_starfighter_horizontally (col_loc, tgt_col)
			end
		end

feature --debug string generation functions

	generate_starfighter_pass_action_debug_string: STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("    The Starfighter(id:")
			Result.append (war_grid.starfighter.id.out)
			Result.append (") passes at location [")
			Result.append (war_grid.row_nb_to_letter (war_grid.starfighter.row_loc))
			Result.append (",")
			Result.append ((war_grid.starfighter.col_loc-1).out)
			Result.append ("], doubling regen rate.")
		end

	generate_starfighter_fire_action_debug_string (spawned_projectiles: LIST[PROJECTILE]): STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("    The Starfighter(id:")
			Result.append (war_grid.starfighter.id.out)
			Result.append (") fires at location [")
			Result.append (war_grid.row_nb_to_letter (war_grid.starfighter.row_loc))
			Result.append (",")
			Result.append ((war_grid.starfighter.col_loc-1).out)
			Result.append ("].")

			across
				spawned_projectiles is spawned_projectile
			loop
				Result.append ("%N")
				Result.append ("      A friendly projectile(id:")
				Result.append (spawned_projectile.id.out)
				Result.append (") spawns at location ")
				if not spawned_projectile.is_on_grid then
					Result.append ("out of board.")
				else
					Result.append ("[")
					Result.append (war_grid.row_nb_to_letter (spawned_projectile.row_loc))
					Result.append (",")
					Result.append ((spawned_projectile.col_loc-1).out)
					Result.append ("].")
				end
			end
		end

	generate_starfighter_special_action_debug_string (power_type_used: INTEGER): STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("    The Starfighter(id:")
			Result.append (war_grid.starfighter.id.out)
			Result.append (") uses special, ")
			if power_type_used = 1 then
				-- recall
				Result.append ("teleporting to: [")
				Result.append (war_grid.row_nb_to_letter (war_grid.starfighter.row_loc))
				Result.append (",")
				Result.append ((war_grid.starfighter.col_loc-1).out)
				Result.append ("]")
			elseif power_type_used = 2 then
				-- repair
			elseif power_type_used = 3 then
				-- overcharge
				-- TODO
			elseif power_type_used = 4 then
				-- deploy drones
				Result.append("clearing projectiles with drones.")
			elseif power_type_used = 5 then
				-- orbital strike
				-- TODO
			end

		end

	generate_starfighter_move_action_debug_string: STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("    The Starfighter(id:")
			Result.append (id.out)
			Result.append (") moves: [")
			Result.append (war_grid.row_nb_to_letter (prev_row_loc))
			Result.append (",")
			Result.append ((prev_col_loc-1).out)
			Result.append ("] -> [")
			Result.append (war_grid.row_nb_to_letter (row_loc))
			Result.append (",")
			Result.append ((col_loc-1).out)
			Result.append ("]")
		end

feature -- private helper functions

	move_starfighter_vertically (orig_row: INTEGER ; tgt_row: INTEGER)
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			signed_step: INTEGER -- either 1 (going down) or -1 (going up)
			from_index: INTEGER
			to_index: INTEGER
			state_access: STATE_ACCESS
			state: STATE
		do
			war_grid := war_grid_access.m
			state := state_access.m
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
					if not war_grid.starfighter.is_dead then
						war_grid.starfighter.set_loc (war_grid.starfighter.row_loc+signed_step, war_grid.starfighter.col_loc)
						energy := energy - move_cost
						war_grid.collision_handler.handle_starfighter_initiated_collision (state.debug_string.starfighter_action_code_delayed)
					end
				end
			end
		end

	move_starfighter_horizontally (orig_col: INTEGER ; tgt_col: INTEGER)
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			signed_step: INTEGER -- either 1 (going down) or -1 (going up)
			from_index: INTEGER
			to_index: INTEGER
			state_access: STATE_ACCESS
			state: STATE
		do
			war_grid := war_grid_access.m
			state := state_access.m
			if orig_col /= tgt_col then

				-- calculate step sign
				if orig_col < tgt_col then
					signed_step := 1
					from_index := orig_col
					to_index := tgt_col-1
				else
					signed_step := -1
					from_index := tgt_col
					to_index := orig_col-1
				end

				-- move starfighter vertically
				across
					from_index |..| to_index is step
				loop
					if not war_grid.starfighter.is_dead then
						war_grid.starfighter.set_loc (war_grid.starfighter.row_loc, war_grid.starfighter.col_loc+signed_step)
						energy := energy - move_cost
						war_grid.collision_handler.handle_starfighter_initiated_collision (state.debug_string.starfighter_action_code_delayed)
					end
				end
			end
		end

feature -- private helper functions

	calculate_game_attributes
	local
		setup_access: SETUP_ACCESS
		setup: SETUP
	do
		setup := setup_access.m
		health := setup.steps.at (1).health + setup.steps.at (2).health + setup.steps.at (3).health
		max_health := health
		energy := setup.steps.at (1).energy + setup.steps.at (2).energy + setup.steps.at (3).energy
		max_energy := energy
		regen_health := setup.steps.at (1).regen_health + setup.steps.at (2).regen_health + setup.steps.at (3).regen_health
		regen_energy := setup.steps.at (1).regen_energy + setup.steps.at (2).regen_energy + setup.steps.at (3).regen_energy
		armour := setup.steps.at (1).armour + setup.steps.at (2).armour + setup.steps.at (3).armour
		vision := setup.steps.at (1).vision + setup.steps.at (2).vision + setup.steps.at (3).vision
		move := setup.steps.at (1).move + setup.steps.at (2).move + setup.steps.at (3).move
		move_cost := setup.steps.at (1).move_cost + setup.steps.at (2).move_cost + setup.steps.at (3).move_cost

		if attached {WEAPON_SETUP} setup.steps.at (1) as chosen_weapon then
			projectile_pattern := chosen_weapon.selection_made_string
			projectile_damage := chosen_weapon.projectile_damage
			projectile_cost := chosen_weapon.projectile_cost
			projectile_cost_unites := chosen_weapon.projectile_cost_unites
		end

		power := setup.last_step
	end

feature -- queires

	out : STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("  Starfighter:")
			Result.append ("%N")
			Result.append ("    [")
			Result.append (id.out)
			Result.append (",")
			Result.append ("S")
			Result.append ("]->health:")
			Result.append (health.out)
			Result.append ("/")
			Result.append (max_health.out)
			Result.append (", energy:")
			Result.append (energy.out)
			Result.append ("/")
			Result.append (max_energy.out)
			Result.append (", Regen:")
			Result.append (regen_health.out)
			Result.append ("/")
			Result.append (regen_energy.out)
			Result.append (", Armour:")
			Result.append (armour.out)
			Result.append (", Vision:")
			Result.append (vision.out)
			Result.append (", Move:")
			Result.append (move.out)
			Result.append (", Move Cost:")
			Result.append (move_cost.out)
			Result.append (", location:[")
			Result.append (war_grid.row_nb_to_letter (row_loc))
			Result.append (",")
			Result.append ((col_loc-1).out)
			Result.append ("]")
			Result.append ("%N")
			Result.append ("      Projectile Pattern:")
			Result.append (projectile_pattern)
			Result.append (", Projectile Damage:")
			Result.append (projectile_damage.out)
			Result.append (", Projectile Cost:")
			Result.append (projectile_cost.out)
			Result.append (" (")
			Result.append (projectile_cost_unites)
			Result.append (")")
			Result.append ("%N")
			Result.append ("      Power:")
			Result.append (power.selection_made_string)
			Result.append ("%N")
			Result.append ("      score:")
			Result.append (focus.get_value.out)
		end

end

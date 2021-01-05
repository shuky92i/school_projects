note
	description: "Summary description for {POWER_SETUP}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	POWER_SETUP

create
	make_default

feature -- initialization

	make_default
		do
			option_1 := "Recall (50 energy): Teleport back to spawn."
			option_2 := "Repair (50 energy): Gain 50 health, can go over max health. Health regen will not be in effect if over cap."
			option_3 := "Overcharge (up to 50 health): Gain 2*health spent energy, can go over max energy. Energy regen will not be in effect if over cap."
			option_4 := "Deploy Drones (100 energy): Clear all projectiles."
			option_5 := "Orbital Strike (100 energy): Deal 100 damage to all enemies, affected by armour."

			selections_string := get_options_string
			create output_string.make_empty
			select_option(1) -- `Standard` as default

			create selection_made_string.make_empty

			-- defalut selection
			selection_made := 1
			selection_made_string := option_1
			select_option (1)
		end

feature -- attributes

	selections_string: STRING
	output_string: STRING
	selection_made: INTEGER

	-- selection attributes
	selection_made_string: STRING


feature {NONE} -- private attributes

	option_1: STRING
	option_2: STRING
	option_3: STRING
	option_4: STRING
	option_5: STRING

feature -- selection routine

	select_option(i: INTEGER)
		do
			create output_string.make_from_string (selections_string)
			selection_made := i
			if selection_made = 1 then
				selection_made_string := option_1
				output_string.append (option_1)
			elseif selection_made = 2 then
				selection_made_string := option_2
				output_string.append (option_2)
			elseif selection_made = 3 then
				selection_made_string := option_3
				output_string.append (option_3)
			elseif selection_made = 4 then
				selection_made_string := option_4
				output_string.append (option_4)
			elseif selection_made = 5 then
				selection_made_string := option_5
				output_string.append (option_5)
			end
		end

	inact_power
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			state_access: STATE_ACCESS
			state: STATE
		do
			war_grid := war_grid_access.m
			state := state_access.m
			war_grid.starfighter.apply_regeneration
			if selection_made = 1 then
				war_grid.starfighter.energy := war_grid.max_of_two_integers (war_grid.starfighter.energy - 50, 0)
				war_grid.starfighter.set_spawn_loc (war_grid.row_count)
				war_grid.collision_handler.handle_starfighter_initiated_collision (state.debug_string.starfighter_action_code_delayed)
			elseif selection_made = 2 then
				war_grid.starfighter.energy := war_grid.max_of_two_integers (war_grid.starfighter.energy - 50, 0)
				war_grid.starfighter.health := war_grid.starfighter.health + 50
			elseif selection_made = 3 then
				if war_grid.starfighter.health > 50 then
					war_grid.starfighter.health := war_grid.starfighter.health - 50
					war_grid.starfighter.energy := war_grid.starfighter.energy + 2 * 50
				else
					war_grid.starfighter.energy := war_grid.starfighter.energy + 2 * (war_grid.starfighter.health - 1)
					war_grid.starfighter.health := 1
				end
			elseif selection_made = 4 then
				war_grid.starfighter.energy := war_grid.max_of_two_integers (war_grid.starfighter.energy - 100, 0)
				across
					war_grid.projectiles is projectile
				loop
					projectile.kill (0, "Starfighter")
					-- report projectile neutralized to delayed starfighter action
					state.debug_string.insert_entry (state.debug_string.starfighter_action_code_delayed, projectile.generate_projectile_neutralized_debug_string)
				end
			elseif selection_made = 5 then
				across
					war_grid.enemies is enemy
				loop
					enemy.health := enemy.health - war_grid.max_of_two_integers (100-enemy.armour, 0)
					if enemy.health <= 0 then
						enemy.health := 0
						enemy.kill (0, "Starfighter")
						state.debug_string.insert_entry (state.debug_string.friendly_projectile_action_code_delayed, enemy.generate_enemy_death_debug_string)
					end
				end
			end
		end

feature -- queries

	get_power_energy_cost: INTEGER
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			if selection_made = 1 then
				Result := 50
			elseif selection_made = 2 then
				Result := 50
			elseif selection_made = 3 then
				Result := war_grid.min_of_two_integers (war_grid.starfighter.health-1, 50)
			elseif selection_made = 4 then
				Result := 100
			elseif selection_made = 5 then
				Result := 100
			end
		end

feature {NONE} -- private helper strings

	get_options_string: STRING
		do
			create Result.make_empty
			Result.append ("  1:")
			Result.append (option_1);
			Result.append ("%N")
			Result.append ("  2:")
			Result.append (option_2)
			Result.append ("%N")
			Result.append ("  3:")
			Result.append (option_3)
			Result.append ("%N")
			Result.append ("  4:")
			Result.append (option_4)
			Result.append ("%N")
			Result.append ("  5:")
			Result.append (option_5)
			Result.append ("%N")
			Result.append ("  Power Selected:")
		end

end

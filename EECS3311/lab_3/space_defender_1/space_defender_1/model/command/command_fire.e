note
	description: "Summary description for {COMMAND_FIRE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	COMMAND_FIRE

inherit
	COMMAND

create
	make

feature -- Initialization
	make
			-- Initialization for `Current'.
		do
			is_command_turnable := true
		end

feature -- mutators

	perform_command: ARRAYED_LIST[STRING]
		local
			collision_happened: BOOLEAN
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			state_message: STRING
			proj_movs_results: PAIR[ARRAYED_LIST[STRING], BOOLEAN]
			state_messages: ARRAYED_LIST[STRING]
		do
			create state_message.make_empty

			-- Rerieve war_grid singleton
			war_grid := war_grid_access.m

			-- Move all existing projectiles (First Part of the turn)
			proj_movs_results := move_all_existing_projectiles
			state_messages := proj_movs_results.first
			collision_happened := proj_movs_results.second

			-- Spawn a new projectile (Second Part of the turn)
			if not collision_happened then
				war_grid.projectiles.extend (create {PROJECTILE}.make (war_grid.starfighter.row_loc, war_grid.starfighter.col_loc+1))
				war_grid.apply_projectiles_loc

				-- Create relevant state message
				state_message.append ("  The Starfighter fires a projectile at: [")
				state_message.append (war_grid.row_nb_to_letter (war_grid.starfighter.row_loc))
				state_message.append (",")
				state_message.append ((war_grid.starfighter.col_loc-1).out) -- we deduct 1 because we initialized at column 2
				state_message.append ("]")
				state_messages.extend (state_message)
			end

			Result := state_messages
		end

	reverse_command
		do
			reverse_all_projectiles_once
		end
end

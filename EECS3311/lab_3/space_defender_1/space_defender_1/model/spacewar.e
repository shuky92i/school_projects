note
	description: "A default business model."
	author: "Jackie Wang"
	date: "$Date$"
	revision: "$Revision$"

class
	SPACEWAR

inherit
	ANY
		redefine
			out
		end

create {SPACEWAR_ACCESS}
	make

feature {NONE} -- Initialization
	make
			-- Initialization for `Current'.
		do
			-- At first we display welcoming mesasge
			init_stage := true
			init_state := "  Welcome to Space Defender Version 1."
			in_game := false

			abort_stage := false
			abort_state := "  Game has been exited."

			game_over_state := "  The game is over. Better luck next time!"

			-- Init Undo/Redo list
			create command_list.make (10)
			command_list_cursor := 0

			-- Error handling at init
			last_command_resulte_in_error := false
			create last_error_content.make_empty

			-- Undo/Redo state numbering
			last_command_was_undo := false
			last_command_was_redo := false
		end

feature -- model attributes
	-- Initial state with welcoming message
	init_state: STRING
	init_stage: BOOLEAN
	in_game: BOOLEAN

	abort_state: STRING
	abort_stage: BOOLEAN

	game_over_state: STRING

	-- Implementig Undo/Redo
	command_list: ARRAYED_LIST[COMMAND]
	command_list_cursor: INTEGER

	-- Error handling
	last_command_resulte_in_error: BOOLEAN
	last_error_content: STRING

	-- Undo/Redo state numbering
	last_command_was_undo: BOOLEAN
	last_command_was_redo: BOOLEAN

	-- Game state management: state_major.state_minor (For example: 2.1)
	state_major: INTEGER
	state_minor: INTEGER

feature -- model operations

	play (row: INTEGER_32 ; column: INTEGER_32 ; player_mov: INTEGER_32 ; project_mov: INTEGER_32)
		require
			3 <= row and row <= 10 and 5 <= column and column <= 30
			and
			1 <= player_mov and player_mov <= 40
			and
			1 <= project_mov and project_mov <= 5
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			-- We are in the middle of a game
			if in_game then
				declare_error ("  Please end the current game before starting a new one.")

			-- We are not in game
			else
				-- Ensure movement parameter does not exceed size of grid
				if player_mov > row-1+column-1 then
					declare_error ("  Starfighter movement should not exceed row - 1 + column - 1 size of the board.")
				else
					war_grid := war_grid_access.m
					war_grid.reshape (row, column, player_mov, project_mov)
					command_list.extend (create {COMMAND_PLAY}.make (row))
					command_list_cursor := command_list.count
					in_game := true
				end
			end

		end

	fire
		do
			if not in_game then
				declare_error ("  Not in game.")

			-- We are in game
			else
				cut_command_list
				command_list.extend (create {COMMAND_FIRE}.make)
				command_list_cursor := command_list.count
			end
		end

	pass
		do
			if not in_game then
				declare_error ("  Not in game.")

			-- We are in game
			else
				cut_command_list
				command_list.extend (create {COMMAND_PASS}.make)
				command_list_cursor := command_list.count
			end
		end

	move (to_row: INTEGER ; to_col: INTEGER)
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			if not in_game then
				declare_error ("  Not in game.")

			-- We are in game
			else
				war_grid := war_grid_access.m

				-- trying to move beyond the board
				if (to_row > war_grid.row_count) or (to_col > war_grid.col_count) then
					declare_error ("  The location to move to is outside of the board.")

				-- trying to move beyond player_max_moves
				elseif absolute_value(to_row-war_grid.starfighter.row_loc) + absolute_value(to_col-war_grid.starfighter.col_loc) > war_grid.player_max_mov then
					declare_error ("  The location to move to is out of the Starfighter's movement range.")

				-- trying to move to current location
				elseif (war_grid.starfighter.row_loc = to_row) and (war_grid.starfighter.col_loc = to_col) then
					declare_error ("  The Starfighter is already at that location.")

				else
					cut_command_list
					command_list.extend (create {COMMAND_MOVE}.make (to_row, to_col))
					command_list_cursor := command_list.count
				end

			end
		end

	undo
		local
			current_command: COMMAND
		do
			if not in_game then
				declare_error ("  Not in game.")

			-- we are in game, which means command_list_cursor > 0
			-- We are in game and a turnable command was performed (after "play" - which is the first command)
			elseif command_list_cursor > 2 then
				current_command := command_list.at (command_list_cursor)
				if current_command.is_command_turnable then
					current_command.reverse_command
					command_list_cursor := command_list_cursor-1
					current_command := command_list.at (command_list_cursor)
					if current_command.is_command_turnable then
						current_command.reverse_command
						last_command_was_undo := true
					end
				end

			-- We are in game and exactly at the command that came after "play"
			elseif command_list_cursor = 2 then
				command_list_cursor := 1 -- Play command
				current_command := command_list.at (command_list_cursor)
				current_command.reverse_all_projectiles_once
				last_command_was_undo := true

			-- cursor is on command "play"
			elseif command_list_cursor = 1 then
				declare_error ("  Nothing left to undo.")
			end

		end

	redo
		do
			if not in_game then
				declare_error ("  Not in game.")
			else
				-- We are in game and an there is something to be "redone"
				if command_list_cursor < command_list.count then
					command_list_cursor := command_list_cursor+1
				else
					declare_error ("  Nothing left to redo.")
				end
			end
		end

	abort
		do
			if in_game then
				abort_stage := true

				-- Init state and Undo/Redo list
				in_game := false
				create command_list.make (10)
				command_list_cursor := 0
			else
				declare_error ("  Not in game.")
			end
		end

	reset
			-- Reset model state.
		do
			make
		end

feature {NONE} -- private helper functins

	declare_error (error_content: STRING)
		do
			last_command_resulte_in_error := true
			last_error_content := error_content
		end

	cut_command_list
		local
			new_command_list: ARRAYED_LIST[COMMAND]

		do
			create new_command_list.make (10)
			across
				1 |..| command_list_cursor is i
			loop
				new_command_list.extend (command_list.at (i))
			end
			command_list := new_command_list
		end

	absolute_value (x: INTEGER): INTEGER
		do
			Result := x
			if x < 0 then
				Result := -x
			end
		end

feature -- queries
	out : STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			last_state_flag: STRING
			last_state_content: STRING
			state_messages: ARRAYED_LIST[STRING]
		do
			create Result.make_empty
			create last_state_content.make_empty
			if init_stage then
				create Result.make_from_string(init_state)
				init_stage := false
			elseif abort_stage then
				create Result.make_from_string ("  ")
				abort_stage := false
				state_major := state_major + 1
				state_minor := 0
				last_state_flag := "ok"
				Result.append ("state:")
				Result.append (state_major.out)
				Result.append (".")
				Result.append (state_minor.out)
				Result.append (", ")
				Result.append (last_state_flag)
				Result.append ("%N")
				Result.append (last_state_content)
				Result.append (abort_state)
			else
				war_grid := war_grid_access.m
				if last_command_resulte_in_error then
					state_minor := state_minor + 1
					last_state_flag := "error"
					last_state_content := last_error_content
				else
					if not last_command_was_undo then
						state_major := state_major + 1
					else
						state_major := state_major - 1
					end
					state_minor := 0
					last_state_flag := "ok"
					if command_list.count > 1 then
						if command_list_cursor /= 1 then
							state_messages := command_list.at (command_list_cursor).perform_command
							across
								state_messages is state_msg
							loop
								last_state_content.append (state_msg)
								last_state_content.append ("%N")
							end
						else
							war_grid.reset
						end

					end
					last_state_content.append (war_grid.to_string)

					if command_list.at (command_list_cursor).collision_happened_game_over then
						last_state_content.append ("%N")
						last_state_content.append (game_over_state)
						-- Init state and Undo/Redo list
						in_game := false
						create command_list.make (10)
						command_list_cursor := 0
					end
				end

				create Result.make_from_string ("  ")
				Result.append ("state:")
				Result.append (state_major.out)
				Result.append (".")
				Result.append (state_minor.out)
				Result.append (", ")
				Result.append (last_state_flag)
				Result.append ("%N")
				Result.append (last_state_content)

				-- Reset error to keep things consistant
				last_command_resulte_in_error := false
				last_command_was_undo := false
				last_error_content.make_empty
			end
		end
end





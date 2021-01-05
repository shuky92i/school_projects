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
		local
			state_access: STATE_ACCESS
		do
			state_header := state_access.m
			init_stage := true
			create current_state_string.make_empty
			create last_command.make_empty
			last_move_to_tgt_row := 0
			last_move_to_tgt_col := 0
			already_executed := false
		end

feature -- model attributes

	-- Initial state with welcoming message
	init_stage: BOOLEAN

	current_state_string: STRING
	state_header: STATE

	last_command: STRING
	last_move_to_tgt_row: INTEGER
	last_move_to_tgt_col: INTEGER

	game_aborted: BOOLEAN
	setup_aborted: BOOLEAN

	already_executed: BOOLEAN -- for handling setup_next during game


feature -- model operations

	play (row: INTEGER_32 ; column: INTEGER_32 ; g_threshold: INTEGER_32 ; f_threshold: INTEGER_32 ; c_threshold: INTEGER_32 ; i_threshold: INTEGER_32 ; p_threshold: INTEGER_32)
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			setup_access: SETUP_ACCESS
			setup: SETUP
		do
			war_grid := war_grid_access.m
			setup := setup_access.m

			if not setup.setup_has_begun then
				setup.setup_has_begun := true
				war_grid.reshape (row, column, g_threshold, f_threshold, c_threshold, i_threshold, p_threshold)
				current_state_string := setup.get_current_selection_string
				state_header.name := "weapon setup"
				state_header.error := "ok"

			else
				if setup.current_step <= 5 then
					-- in setup stage
					process_already_in_setup_error

				else
					-- in game
					process_play_while_during_game_error
				end
			end
		end

	setup_select (value: INTEGER_32)
		local
			setup_access: SETUP_ACCESS
			setup: SETUP
		do
			setup := setup_access.m
			if setup.setup_has_begun = false then
				process_not_in_setup_except_summary_error
			else
				setup.setup_select (value)
				current_state_string := setup.get_current_selection_string
				state_header.error := "ok"
			end
		end

	setup_next (state: INTEGER_32)
		local
			setup_access: SETUP_ACCESS
			setup: SETUP
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			setup := setup_access.m
			if setup.setup_has_begun = false then
				process_not_in_setup_error
			else
				war_grid := war_grid_access.m
				setup.setup_next (state)
				state_header.error := "ok"
				if setup.current_step <= 5 then
					-- setup stage
					if setup.current_step = 2 then
						state_header.name := "armour setup"
					elseif setup.current_step = 3 then
						state_header.name := "engine setup"
					elseif setup.current_step = 4 then
						state_header.name := "power setup"
					else
						state_header.name := "setup summary"
					end
					current_state_string := setup.get_current_selection_string
				else
					if not already_executed then
						-- game starts
						war_grid.apply_entities_locs
						state_header.major := 0
						state_header.minor := 0
						war_grid.starfighter.calculate_game_attributes
						state_header.update_state_name_in_game
						current_state_string := get_abstract_state_content
						already_executed := true
					else
						process_not_in_setup_error
						state_header.update_state_name_in_game
					end
				end
			end
		end

	setup_back (state: INTEGER_32)
		local
			setup_access: SETUP_ACCESS
			setup: SETUP
		do
			setup := setup_access.m
			if setup.setup_has_begun = false then
				process_not_in_setup_error
			else
				setup.setup_back (state)
				-- setup stage
				if setup.current_step >= 1 then
					if setup.current_step = 1 then
						state_header.name := "weapon setup"
					elseif setup.current_step = 2 then
						state_header.name := "armour setup"
					elseif setup.current_step = 3 then
						state_header.name := "engine setup"
					elseif setup.current_step = 4 then
						state_header.name := "power setup"
					end
					current_state_string := setup.get_current_selection_string

				-- welcome state
				else
					init_stage := true
					state_header.name := "not started"
				end
			end
		end

	pass
		local
			setup_access: SETUP_ACCESS
			setup: SETUP
		do
			setup := setup_access.m
			if setup.setup_has_begun = false then
				process_not_in_game_error
			else
				if setup.current_step <= 5 then
				-- during setup
				process_not_in_game_error

				-- in game
				else
					last_command := "pass"
					process_command
				end
			end

		end

	move (to_row: INTEGER_32 ; to_col: INTEGER_32)
		local
			setup_access: SETUP_ACCESS
			setup: SETUP
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			setup := setup_access.m
			war_grid := war_grid_access.m
			if setup.setup_has_begun = false then
				process_not_in_game_error
			else
				if setup.current_step <= 5 then
				-- during setup
				process_not_in_game_error

				-- in game
				else
					-- trying to move beyond player_max_moves
					if absolute_value(to_row-war_grid.starfighter.row_loc) + absolute_value(to_col-war_grid.starfighter.col_loc) > war_grid.starfighter.move then
						process_out_of_move_range_error
					else
						if (war_grid.starfighter.row_loc = to_row) and (war_grid.starfighter.col_loc = to_col) then
							process_moving_to_current_position_error
						elseif war_grid.starfighter.energy <= war_grid.starfighter.move_cost then
							process_too_weak_to_move_error
						else
							last_command := "move"
							last_move_to_tgt_row := to_row
							last_move_to_tgt_col := to_col
							process_command
						end
					end
				end
			end
		end

	fire
		local
			setup_access: SETUP_ACCESS
			setup: SETUP
			war_grid: WAR_GRID
			war_grid_access: WAR_GRID_ACCESS
		do
			setup := setup_access.m
			war_grid := war_grid_access.m
			if setup.setup_has_begun = false then
				process_not_in_game_error
			else
				if setup.current_step <= 5 then
				-- during setup
					process_not_in_game_error

				-- in game
				else
					if war_grid.starfighter.energy < war_grid.starfighter.projectile_cost then
						process_too_weak_to_fire_error
					else
						last_command := "fire"
						process_command
					end
				end
			end
		end

	abort
		local
			setup_access: SETUP_ACCESS
			setup: SETUP
		do
			setup := setup_access.m
			if not setup.setup_has_begun then
				process_abort_error
			else
				if setup.current_step <= 5 then
					setup_aborted := true
					setup.current_step := 1
					if setup.setup_has_begun then
						setup.setup_has_begun := false
					end
				else
					game_aborted := true
					if setup.setup_has_begun then
						setup.setup_has_begun := false
					end
				end
				-- in game or in setup
				state_header.name := "not started"
				state_header.error := "ok"
			end
		end

	special
		local
			setup_access: SETUP_ACCESS
			setup: SETUP
			war_grid: WAR_GRID
			war_grid_access: WAR_GRID_ACCESS
		do
			setup := setup_access.m
			war_grid := war_grid_access.m
			if setup.setup_has_begun = false then
				process_not_in_game_error
			else
				if setup.current_step <= 5 then
				-- during setup
					process_not_in_game_error

				-- in game
				else
					if war_grid.starfighter.energy < war_grid.starfighter.power.get_power_energy_cost  then
						process_too_weak_to_use_power_error
					else
						last_command := "special"
						process_command
					end
				end
			end
		end

	toggle_debug_mode
		local
			setup_access: SETUP_ACCESS
			setup: SETUP
		do
			state_header.error := "ok"
			state_header.toggle_debug_mode
			setup := setup_access.m
			if state_header.is_debugging then
				current_state_string := "  In debug mode."
			else
				current_state_string := "  Not in debug mode."
			end
			-- update state numbers if in game
			state_header.minor := state_header.minor+1
			if setup.current_step > 5 then
				state_header.update_state_name_in_game
			end
		end

	reset
			-- Reset model state.
		local
			setup_access: SETUP_ACCESS
			setup: SETUP
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			setup := setup_access.m
			make -- reset SPACEWAR
			war_grid.reset -- reset WAR_GRID
			setup.reset -- reset SETUP
			init_stage := false
		end

feature {NONE} -- private helper functions

	get_abstract_state_content: STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append (war_grid.starfighter.out) -- starfighter
			Result.append ("%N")
			if state_header.is_debugging then
				Result.append (state_header.debug_string.out) -- debug string
				Result.append ("%N")
			end
			Result.append (grid_as_string) -- grid
		end

	grid_as_string: STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			war_grid.clear_grid_dust
			if not state_header.is_debugging then
				war_grid.apply_grid_dust
			else
				war_grid.clear_grid_dust
			end
			Result := war_grid.out
		end

	perform_turn
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			war_grid.perform_phase_1
			war_grid.perform_phase_2
			war_grid.perform_phase_3 (last_command, last_move_to_tgt_row, last_move_to_tgt_col)
			war_grid.perform_phase_4
			war_grid.perform_phase_5 (last_command)
			war_grid.perform_phase_6
			war_grid.perform_phase_7
			if war_grid.starfighter.is_dead then
				state_header.name := "not started"
			end
		end

	process_command
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m

			-- update major.minor
			state_header.major := state_header.major+1
			state_header.minor := 0
			state_header.error := "ok"
			state_header.update_state_name_in_game

			-- perform turn
			perform_turn

			-- apply entities locs
			war_grid.apply_entities_locs

			-- update current_state_string
			current_state_string := get_abstract_state_content -- takes care of in_debugging case
		end

	process_already_in_setup_error
		do
			state_header.error := "error"
			current_state_string := "  Already in setup mode."
		end

	process_play_while_during_game_error
		do
			state_header.minor := state_header.minor+1
			state_header.error := "error"
			current_state_string := "  Already in a game. Please abort to start a new one."
			state_header.update_state_name_in_game
		end

	process_not_in_game_error
		do
			state_header.minor := state_header.minor+1
			state_header.error := "error"
			current_state_string := "  Command can only be used in game."
		end

	process_out_of_move_range_error
		do
			state_header.minor := state_header.minor+1
			state_header.error := "error"
			current_state_string := "  Out of movement range."
			state_header.update_state_name_in_game
		end

	process_too_weak_to_fire_error
		do
			state_header.minor := state_header.minor+1
			state_header.error := "error"
			current_state_string := "  Not enough resources to fire."
			state_header.update_state_name_in_game
		end

	process_too_weak_to_move_error
		do
			state_header.minor := state_header.minor+1
			state_header.error := "error"
			current_state_string := "  Not enough resources to move."
			state_header.update_state_name_in_game
		end

	process_moving_to_current_position_error
		do
			state_header.minor := state_header.minor+1
			state_header.error := "error"
			current_state_string := "  Already there."
			state_header.update_state_name_in_game
		end

	process_too_weak_to_use_power_error
		do
			state_header.minor := state_header.minor+1
			state_header.error := "error"
			current_state_string := "  Not enough resources to use special."
			state_header.update_state_name_in_game
		end

	process_not_in_setup_error
		do
			state_header.minor := state_header.minor+1
			state_header.error := "error"
			current_state_string := "  Command can only be used in setup mode."
		end

	process_not_in_setup_except_summary_error
		do
			state_header.minor := state_header.minor+1
			state_header.error := "error"
			current_state_string := "  Command can only be used in setup mode (excluding summary in setup)."
		end

	process_abort_error
		do
			state_header.minor := state_header.minor+1
			state_header.error := "error"
			current_state_string := "  Command can only be used in setup mode or in game."
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
			last_state_content: STRING
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			create Result.make_empty
			create last_state_content.make_empty
			if init_stage then
				Result.append(state_header.get_state_title)
				Result.append ("%N")
				Result.append ("  Welcome to Space Defender Version 2.")
				init_stage := false
			elseif game_aborted then
				Result.append(state_header.get_state_title)
				Result.append ("%N")
				Result.append ("  Exited from game.")
				reset
				game_aborted := false
			elseif setup_aborted then
				Result.append(state_header.get_state_title)
				Result.append ("%N")
				Result.append ("  Exited from setup mode.")
				reset
				setup_aborted := false
			else
				Result.append (state_header.get_state_title)
				Result.append ("%N")
				Result.append (current_state_string)
				if war_grid.starfighter.is_dead then
					Result.append ("%N")
					Result.append ("  The game is over. Better luck next time!")
					reset
				end
			end
			state_header.reset_debug_string
		end

end





note
	description: "Summary description for {COMMAND_MOVE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	COMMAND_MOVE
inherit
	COMMAND

create
	make

feature -- Initialization
	make (target_row_loc: INTEGER ; target_col_loc: INTEGER)
			-- Initialization for `Current'.
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			is_command_turnable := true

			war_grid := war_grid_access.m
			orig_row_loc := war_grid.starfighter.row_loc
			orig_col_loc := war_grid.starfighter.col_loc

			new_row_loc := target_row_loc
			new_col_loc := target_col_loc

			collision_happened_game_over := false
		end

feature {NONE }-- privat eattributes

	-- Original coordinates of the starfighter
	orig_row_loc: INTEGER
	orig_col_loc: INTEGER

	-- New coordiantes of the starfighter
	new_row_loc: INTEGER
	new_col_loc: INTEGER

feature -- mutators

	perform_command: ARRAYED_LIST[STRING]
		local
			collision_happened: BOOLEAN
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			state_message: STRING
			proj_movs_results: PAIR[ARRAYED_LIST[STRING], BOOLEAN]
			state_messages: ARRAYED_LIST[STRING]
			collision_happened_along_the_way: BOOLEAN
		do
			create state_message.make_empty

			-- Rerieve war_grid singleton
			war_grid := war_grid_access.m

			-- Move all existing projectiles (First Part of the turn)
			proj_movs_results := move_all_existing_projectiles
			state_messages := proj_movs_results.first
			collision_happened := proj_movs_results.second
			war_grid.apply_projectiles_loc

			-- Move starfighter (Second Part of the turn)
			if not collision_happened then

				-- move starfighter vertically
				collision_happened_along_the_way := move_starfighter_vertically (orig_row_loc, new_row_loc)
				if collision_happened_along_the_way then

					-- collision happened while moving vertically, game ends
					war_grid.starfighter.kill
					war_grid.apply_starfighter_loc

					-- append collision report message
					state_messages.extend (get_starfighter_movement_collision_string(orig_row_loc, orig_col_loc))
					collision_happened_game_over := true

				else
					collision_happened_along_the_way := move_starfighter_horizontally (orig_col_loc, new_col_loc)
					if collision_happened_along_the_way then

						-- collision happened while moving horizontally, game ends
						war_grid.starfighter.kill
						war_grid.apply_starfighter_loc
						collision_happened_game_over := true

						-- append collision report message
						state_messages.extend (get_starfighter_movement_collision_string(orig_row_loc, orig_col_loc))

					else
						-- No collision ever happened, starfighter moved from origin to destination successfully
						state_message.append ("  The Starfighter moves: [")
						state_message.append (war_grid.row_nb_to_letter (orig_row_loc))
						state_message.append (",")
						state_message.append ((orig_col_loc-1).out)
						state_message.append ("] -> [")
						state_message.append (war_grid.row_nb_to_letter (war_grid.starfighter.row_loc))
						state_message.append (",")
						state_message.append ((war_grid.starfighter.col_loc-1).out)
						state_message.append ("]")
						state_messages.extend (state_message)
					end
				end
			end

			Result := state_messages
		end

	reverse_command
		local
			success_expected: BOOLEAN
		do
			-- reverse starfighter (horizontally then vertically)
			success_expected := move_starfighter_horizontally (new_col_loc, orig_col_loc)
			success_expected := move_starfighter_vertically (new_row_loc, orig_row_loc)

			reverse_all_projectiles_once
		end

feature {NONE} -- private helper functions

	move_starfighter_vertically (orig_row: INTEGER ; tgt_row: INTEGER): BOOLEAN -- whether a collision happened at some point or not
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			signed_step: INTEGER -- either 1 (going down) or -1 (going up)
			from_index: INTEGER
			to_index: INTEGER
		do
			Result := false -- no collision happened
			war_grid := war_grid_access.m
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
					if Result = false then
						war_grid.starfighter.set_loc (war_grid.starfighter.row_loc+signed_step, war_grid.starfighter.col_loc)
						Result := starfighter_ran_into_a_projectile
					end
				end
			end
			war_grid.apply_starfighter_loc
		end

	move_starfighter_horizontally (orig_col: INTEGER ; tgt_col: INTEGER): BOOLEAN
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			signed_step: INTEGER -- either 1 (going down) or -1 (going up)
			from_index: INTEGER
			to_index: INTEGER
		do
			Result := false -- no collision happened
			war_grid := war_grid_access.m
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
					if Result = false then
						war_grid.starfighter.set_loc (war_grid.starfighter.row_loc, war_grid.starfighter.col_loc+signed_step)
							Result := starfighter_ran_into_a_projectile
					end
				end
			end
			war_grid.apply_starfighter_loc
		end

	starfighter_ran_into_a_projectile: BOOLEAN
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			Result := false
			across
				war_grid.projectiles is projectile
			loop
				if (projectile.row_loc = war_grid.starfighter.row_loc)
					and
					(projectile.col_loc = war_grid.starfighter.col_loc) then
					Result := true
				end
			end
		end

	get_starfighter_movement_collision_string (from_row_loc: INTEGER ; from_col_loc: INTEGER) : STRING
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			create Result.make_empty
			Result.append ("  The Starfighter moves and collides with a projectile: [")
			Result.append (war_grid.row_nb_to_letter (from_row_loc))
			Result.append (",")
			Result.append ((from_col_loc-1).out)
			Result.append ("] -> [")
			Result.append (war_grid.row_nb_to_letter (war_grid.starfighter.row_loc))
			Result.append (",")
			Result.append ((war_grid.starfighter.col_loc-1).out)
			Result.append ("]")
		end

end

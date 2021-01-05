note
	description: "Summary description for {COMMAND}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	COMMAND

feature -- attributees

	is_command_turnable: BOOLEAN -- can the command be undone/redone?
	collision_happened_game_over: BOOLEAN -- game over flag to be checked by the main model - SPACEWAR

feature -- deferred features

	-- Return a list of state messages regarding the movement of the projectiles and possibly the movement of the starfigghter (depending on the command)
	perform_command: ARRAYED_LIST[STRING]
		deferred
		end

	-- Reverse the operation of the command
	reverse_command
		deferred
		end

feature -- Common features

	-- Result.first is a list of state messages regarding the movement of the projectiles
	-- Result.second = true If a collision happened along the way while moving projectiles. False otherwwise
	move_all_existing_projectiles: PAIR[ARRAYED_LIST[STRING], BOOLEAN]
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			collision_happened: BOOLEAN
			state_message: STRING
			state_messages: ARRAYED_LIST[STRING]

			-- orig coordinates of projectile
			projectile_orig_coord_r: INTEGER
			projectile_orig_coord_c: INTEGER
		do
			war_grid := war_grid_access.m
			collision_happened := false -- To prevent a projectile from moving after colliding with the starfighter
			create state_messages.make (10)
			create Result.make (state_messages, false)

			across
				war_grid.projectiles is cp_projectile
			loop
				projectile_orig_coord_r := cp_projectile.row_loc
				projectile_orig_coord_c := cp_projectile.col_loc
				create state_message.make_empty

				across
					1 |..| war_grid.projectile_mov is hor_step
				loop
					if not collision_happened then
						if cp_projectile.col_loc <= war_grid.col_count then
							cp_projectile.set_loc (cp_projectile.row_loc, cp_projectile.col_loc + 1, true)
						else
							cp_projectile.set_loc (cp_projectile.row_loc, cp_projectile.col_loc + 1, false)
						end

						-- Collision happened
						if (cp_projectile.row_loc = war_grid.starfighter.row_loc)
							and
							(cp_projectile.col_loc = war_grid.starfighter.col_loc) then
							war_grid.starfighter.kill
							war_grid.apply_starfighter_loc
							collision_happened := true
							Result.make (state_messages, true)

							-- Handling collision message due to projectile moving horizontally and colliiding with starfighter
							state_message.append ("  A projectile moves and collides with the Starfighter: [")
							state_message.append (war_grid.row_nb_to_letter (projectile_orig_coord_r))
							state_message.append (",")
							state_message.append ((projectile_orig_coord_c-1).out)
							state_message.append ("] -> [")
							state_message.append (war_grid.row_nb_to_letter (cp_projectile.row_loc))
							state_message.append (",")
							state_message.append ((cp_projectile.col_loc-1).out)
							state_message.append ("]")
							state_messages.extend (state_message)
						end
					end
				end

				-- Handling no-collision message for this projectile	
				if (collision_happened = false) then
					if projectile_orig_coord_c <= war_grid.col_count then
						state_message.append ("  A projectile moves: [")
						state_message.append (war_grid.row_nb_to_letter (projectile_orig_coord_r))
						state_message.append (",")
						state_message.append ((projectile_orig_coord_c-1).out)
						state_message.append ("] -> ")
						if cp_projectile.col_loc > war_grid.col_count then
							state_message.append ("out of the board")
						else
							state_message.append ("[")
							state_message.append (war_grid.row_nb_to_letter (cp_projectile.row_loc))
							state_message.append (",")
							state_message.append ((cp_projectile.col_loc-1).out)
							state_message.append ("]")
						end

						state_messages.extend (state_message)
					end


				end

				-- reset data before looping
				collision_happened := false
			end
		end

	-- reverse all projectile starting from the first one that was created until the last one
	reverse_all_projectiles_once
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			cp_projectile: PROJECTILE
			projectiles_to_delete: ARRAYED_LIST[PROJECTILE]
		do
			war_grid := war_grid_access.m
			create projectiles_to_delete.make (10)
			across
				1 |..| war_grid.projectiles.count is index
			loop
				cp_projectile := war_grid.projectiles.at (index)
				if not cp_projectile.is_at_origin then
					if cp_projectile.col_loc-war_grid.projectile_mov <= war_grid.col_count then
						if cp_projectile.col_loc <= war_grid.col_count then
							cp_projectile.set_loc (cp_projectile.row_loc, cp_projectile.col_loc-war_grid.projectile_mov, true)
						else
							cp_projectile.set_loc (cp_projectile.row_loc, cp_projectile.col_loc-war_grid.projectile_mov, false)
						end
					else
						cp_projectile.set_loc (cp_projectile.row_loc, cp_projectile.col_loc-war_grid.projectile_mov, false)
					end
				else
					projectiles_to_delete.force (cp_projectile)
				end

			end

			across
				projectiles_to_delete is projectile_to_delete
			loop
				war_grid.remove_projectile (projectile_to_delete)
			end

			war_grid.apply_projectiles_loc
		end

end

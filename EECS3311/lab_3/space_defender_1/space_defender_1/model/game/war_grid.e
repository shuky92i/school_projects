note
	description: "Summary description for {WAR_GRID}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	WAR_GRID

create {WAR_GRID_ACCESS}
	make_empty

feature {NONE} -- Initialization

	-- make an empty grid
	make_empty
			-- Initialization for `Current'.
		do
			row_count := 0
			col_count := 0
			create grid.make_filled("_", row_count, col_count)

			player_max_mov := 0
			projectile_mov := 0

			create starfighter.make (row_count)
			create projectiles.make (10)
		end

feature {SPACEWAR} -- Reshape/reset Grid, used only by SPACEWAR

	reshape (rows: INTEGER ; cols: INTEGER ; player_mov: INTEGER ; project_mov: INTEGER)
			-- Initialization for `Current'.
		do
			create starfighter.make (rows)
			create projectiles.make (10)

			row_count := rows+1
			col_count := cols+1
			create grid.make_filled("_", row_count, col_count)

			player_max_mov := player_mov
			projectile_mov := project_mov
		end

	reset
		do
			grid.make_filled("_", row_count, col_count)
			starfighter.set_loc_to_origin
			apply_starfighter_loc

		end

feature -- GRID attributes
	-- Initial state with welcoming message
	grid: ARRAY2[STRING]
	row_count: INTEGER
	col_count: INTEGER
	player_max_mov: INTEGER
	projectile_mov: INTEGER

	-- Game "Characters" (Starfighter and projectiles)
	starfighter: STARFIGHTER
	projectiles: ARRAYED_LIST[PROJECTILE]

feature -- context features

	-- translating grid row indices to relevant row letter (first row is already used for column numbering)
	row_nb_to_letter(row_nb: INTEGER): STRING
		require
			2 <= row_nb and row_nb <= 11
		do
			create Result.make_empty
			if row_nb = 2 then
				Result.append("A")
			elseif row_nb = 3 then
				Result.append("B")
			elseif row_nb = 4 then
				Result.append("C")
			elseif row_nb = 5 then
				Result.append("D")
			elseif row_nb = 6 then
				Result.append("E")
			elseif row_nb = 7 then
				Result.append("F")
			elseif row_nb = 8 then
				Result.append("G")
			elseif row_nb = 9 then
				Result.append("H")
			elseif row_nb = 10 then
				Result.append("I")
			elseif row_nb = 11 then
				Result.append("J")
			end
		end

	-- used to translate enumberation to the business logic
	letter_to_row_nb(letter: STRING): INTEGER
		require
			(letter ~ "A") or (letter ~ "B") or (letter ~ "C") or (letter ~ "D") or (letter ~ "E") or
			(letter ~ "F") or (letter ~ "G") or (letter ~ "H") or (letter ~ "I") or (letter ~ "J")
		do
			if letter ~ "A" then
				Result := 2
			elseif letter ~ "B" then
				Result := 3
			elseif letter ~ "C" then
				Result := 4
			elseif letter ~ "D" then
				Result := 5
			elseif letter ~ "E" then
				Result := 6
			elseif letter ~ "F" then
				Result := 7
			elseif letter ~ "G" then
				Result := 8
			elseif letter ~ "H" then
				Result := 9
			elseif letter ~ "I" then
				Result := 10
			elseif letter ~ "J" then
				Result := 11
			end
		end

feature -- dynamic grid mutators

	apply_starfighter_loc
		do
			if not starfighter.is_starfighter_dead then
				grid[starfighter.row_loc, starfighter.col_loc] := "S"
			else
				grid[starfighter.row_loc, starfighter.col_loc] := "X"
			end
		end

	apply_projectiles_loc
		do
			across
				projectiles is projectile
			loop
				if projectile.col_loc <= col_count  then
					grid[projectile.row_loc, projectile.col_loc] := "*"
				end
			end
		end

	reset_grid_location (row_loc: INTEGER ; col_loc: INTEGER)
		do
			grid[row_loc, col_loc] := "_"
		end

	remove_projectile (proj: PROJECTILE)
	local
		new_projs_list: ARRAYED_LIST[PROJECTILE]
	do
		reset_grid_location (proj.row_loc, proj.col_loc)
		create new_projs_list.make (10)
		across
			projectiles is projectile
		loop
			if projectile /= proj then
				new_projs_list.extend (projectile)
			end
		end
		projectiles := new_projs_list
	end


feature -- Queries

	to_string : STRING
		do
			create Result.make_empty
			across
				1 |..| row_count is r
			loop
				across
					1 |..| col_count is c
				loop
					if r = 1 then
						if c = 1 then
							Result.append ("      ")
							Result.append (c.out)
						elseif (c < 10) and (c < col_count) then
							Result.append ("  ")
							Result.append (c.out)
						elseif (c >= 10) and (c < col_count) then
							Result.append (" ")
							Result.append (c.out)
						end

					else
						if c = 1 then
							Result.append ("    ")
							Result.append (row_nb_to_letter(r))
							Result.append (" ")
						else
							Result.append (grid[r, c])
							if c < col_count then
							Result.append ("  ")
							end
						end
					end
				end
				if r < row_count then
					Result.append ("%N")
				end
			end
		end


end

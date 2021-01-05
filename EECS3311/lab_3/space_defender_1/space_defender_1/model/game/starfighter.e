note
	description: "Summary description for {STARFIGHTER}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	STARFIGHTER

create
	make

feature -- Initialization
	make (grid_row_count: INTEGER)
			-- Initialization for `Current'.
		do
			row_loc := (grid_row_count/2).ceiling+1
			col_loc := 2 -- Init at second colomn after letter
			orig_row_loc := row_loc
			orig_col_loc := col_loc
			is_starfighter_dead := false
		end

feature -- attributes
	-- Initial state with welcoming message
	row_loc: INTEGER
	col_loc: INTEGER

	-- this is where the projectiles was originally created
	orig_row_loc: INTEGER
	orig_col_loc: INTEGER

	-- starfighter state, dead if collision happened with projectile
	is_starfighter_dead: BOOLEAN

feature -- starfighter state mutators

	-- set starfighter location to new location and reset old location with "_"
	-- the new location is always valid as it's handled in main model - WAR_GRID
	set_loc (new_row_loc: INTEGER ; new_col_loc: INTEGER)
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			war_grid := war_grid_access.m
			war_grid.reset_grid_location (row_loc, col_loc)
			row_loc := new_row_loc
			col_loc := new_col_loc
		end

	-- used in WAR_GRID to reset location to origin when resetting the grid
	set_loc_to_origin
		do
			row_loc := orig_row_loc
			col_loc := orig_col_loc
		end

	-- A collision happened, mark the starfighter dead
	kill
		do
			is_starfighter_dead := true
		end
end

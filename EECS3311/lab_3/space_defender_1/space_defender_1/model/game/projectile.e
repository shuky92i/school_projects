note
	description: "Summary description for {PROJECTILE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	PROJECTILE

create
	make

feature -- Initialization
	make (r_loc: INTEGER ; c_loc: INTEGER)
			-- Initialization for `Current'.
		do
			row_loc := r_loc
			col_loc := c_loc

			orig_row_loc := r_loc
			orig_col_loc := c_loc

		end

feature -- attributes
	-- Initial state with welcoming message
	row_loc: INTEGER
	col_loc: INTEGER

	-- this is where the projectiles was originally created
	orig_row_loc: INTEGER 
	orig_col_loc: INTEGER


feature -- Projectile state mutators

	-- set location of projectile to new location and check whether to reset old location with "_"
	-- If projectile is out of board then `reset_flag` is false
	set_loc (new_row_loc: INTEGER ; new_col_loc: INTEGER ; reset_flag: BOOLEAN)
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			if reset_flag then
				war_grid := war_grid_access.m
				war_grid.reset_grid_location (row_loc, col_loc)
			end
			row_loc := new_row_loc
			col_loc := new_col_loc
		end

	-- check if projectile is at the point where it was originally created
	-- used when reversing projctile in order to destroy projectile and delete it if it is (or it's back) to orig location
	is_at_origin: BOOLEAN
		do
			if (row_loc = orig_row_loc) and (col_loc = orig_col_loc) then
				Result := true
			else
				Result := false
			end
		end

end

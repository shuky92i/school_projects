note
	description: "Summary description for {COMMAND_PLAY}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	COMMAND_PLAY

inherit
	COMMAND

create
	make

feature -- Initialization
	make (grid_row_count: INTEGER)
			-- Initialization for `Current'.
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
		do
			is_command_turnable := false

			-- Rerieve war_grid singleton
			war_grid := war_grid_access.m
			war_grid.apply_starfighter_loc
		end

-- adding {NONE} to ensure that I don't use these functions outside the class. "play" cannot be performed or reversed
feature {NONE} -- mutators

	perform_command: ARRAYED_LIST[STRING]
		do
			create Result.make_filled (0)
		end

	reverse_command
		do
		end

end

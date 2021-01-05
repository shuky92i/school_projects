note
	description: ""
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	ETF_MOVE
inherit
	ETF_MOVE_INTERFACE
create
	make
feature -- command
	move(row: INTEGER_32 ; column: INTEGER_32)
		require else
			move_precond(row, column)
		local
			war_grid_access: WAR_GRID_ACCESS
			war_grid: WAR_GRID
			row_in_number_adjusted: INTEGER -- number adjusted to my specific internal model
    	do
			war_grid := war_grid_access.m
			if row = A then
				row_in_number_adjusted := war_grid.letter_to_row_nb ("A")
			elseif row = B then
				row_in_number_adjusted := war_grid.letter_to_row_nb ("B")
			elseif row = C then
				row_in_number_adjusted := war_grid.letter_to_row_nb ("C")
			elseif row = D then
				row_in_number_adjusted := war_grid.letter_to_row_nb ("D")
			elseif row = E then
				row_in_number_adjusted := war_grid.letter_to_row_nb ("E")
			elseif row = F then
				row_in_number_adjusted := war_grid.letter_to_row_nb ("F")
			elseif row = G then
				row_in_number_adjusted := war_grid.letter_to_row_nb ("G")
			elseif row = H then
				row_in_number_adjusted := war_grid.letter_to_row_nb ("H")
			elseif row = I then
				row_in_number_adjusted := war_grid.letter_to_row_nb ("I")
			elseif row = J then
				row_in_number_adjusted := war_grid.letter_to_row_nb ("J")
			end

			model.move (row_in_number_adjusted, column+1) -- we add 1 to column to account for the column where the letters appear
			etf_cmd_container.on_change.notify ([Current])
    	end

end

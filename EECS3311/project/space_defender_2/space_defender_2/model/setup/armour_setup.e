note
	description: "Summary description for {ARMOUR_SETUP}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	ARMOUR_SETUP

inherit
	EFFECT

create
	make_default

feature -- initialization

	make_default
		do
			selections_string := get_options_string
			create output_string.make_empty
			create selection_made_string.make_empty

			-- defalut selection
			selection_made := 1
			selection_made_string := "None"
			select_option (1)
		end

feature -- selection routine

	select_option(i: INTEGER)
		do
			create output_string.make_from_string (selections_string)
			selection_made := i
			if selection_made = 1 then
				selection_made_string := "None"
				output_string.append ("None")
				fill_attributes (50, 0, 1, 0, 0, 0, 1, 0)
			elseif selection_made = 2 then
				selection_made_string := "Light"
				output_string.append ("Light")
				fill_attributes (75, 0, 2, 0, 3, 0, 0, 1)
			elseif selection_made = 3 then
				selection_made_string := "Medium"
				output_string.append ("Medium")
				fill_attributes (100, 0, 3, 0, 5, 0, 0, 3)
			elseif selection_made = 4 then
				selection_made_string := "Heavy"
				output_string.append ("Heavy")
				fill_attributes (200, 0, 4, 0, 10, 0, -1, 5)
			end
		end

feature {NONE} -- private helper strings
	get_options_string: STRING
		do
			create Result.make_empty
			Result.append ("  1:None");
			Result.append ("%N")
			Result.append ("    Health:50, Energy:0, Regen:1/0, Armour:0, Vision:0, Move:1, Move Cost:0")
			Result.append ("%N")
			Result.append ("  2:Light")
			Result.append ("%N")
			Result.append ("    Health:75, Energy:0, Regen:2/0, Armour:3, Vision:0, Move:0, Move Cost:1")
			Result.append ("%N")
			Result.append ("  3:Medium")
			Result.append ("%N")
			Result.append ("    Health:100, Energy:0, Regen:3/0, Armour:5, Vision:0, Move:0, Move Cost:3")
			Result.append ("%N")
			Result.append ("  4:Heavy")
			Result.append ("%N")
			Result.append ("    Health:200, Energy:0, Regen:4/0, Armour:10, Vision:0, Move:-1, Move Cost:5")
			Result.append ("%N")
			Result.append ("  Armour Selected:")
		end
end

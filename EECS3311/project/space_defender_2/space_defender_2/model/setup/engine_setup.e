note
	description: "Summary description for {ENGINE_SETUP}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	ENGINE_SETUP

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
			selection_made_string := "Standard"
			select_option (1)
		end

feature -- selection routine

	select_option(i: INTEGER)
		do
			create output_string.make_from_string (selections_string)
			selection_made := i
			if selection_made = 1 then
				selection_made_string := "Standard"
				output_string.append ("Standard")
				fill_attributes (10, 60, 0, 2, 1, 12, 8, 2)
			elseif selection_made = 2 then
				selection_made_string := "Light"
				output_string.append ("Light")
				fill_attributes (0, 30, 0, 1, 0, 15, 10, 1)
			elseif selection_made = 3 then
				selection_made_string := "Armoured"
				output_string.append ("Armoured")
				fill_attributes (50, 100, 0, 3, 3, 6, 4, 5)
			end
		end

feature {NONE} -- private helper strings
	get_options_string: STRING
		do
			create Result.make_empty
			Result.append ("  1:Standard");
			Result.append ("%N")
			Result.append ("    Health:10, Energy:60, Regen:0/2, Armour:1, Vision:12, Move:8, Move Cost:2")
			Result.append ("%N")
			Result.append ("  2:Light")
			Result.append ("%N")
			Result.append ("    Health:0, Energy:30, Regen:0/1, Armour:0, Vision:15, Move:10, Move Cost:1")
			Result.append ("%N")
			Result.append ("  3:Armoured")
			Result.append ("%N")
			Result.append ("    Health:50, Energy:100, Regen:0/3, Armour:3, Vision:6, Move:4, Move Cost:5")
			Result.append ("%N")
			Result.append ("  Engine Selected:")
		end

end

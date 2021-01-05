note
	description: "Summary description for {WEAPON_SETUP}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	WEAPON_SETUP

inherit
	EFFECT

create
	make_default

feature -- initialization

	make_default
		do
			selections_string := get_options_string
			create output_string.make_empty
			create projectile_cost_unites.make_empty
			create selection_made_string.make_empty

			-- defalut selection
			selection_made := 1
			selection_made_string := "Standard"
			select_option (1)
		end

feature -- specialized attributes

	projectile_damage: INTEGER
	projectile_cost: INTEGER
	projectile_cost_unites: STRING -- "energy" or "health"

feature -- selection routine

	select_option(i: INTEGER)
		do
			create output_string.make_from_string (selections_string)
			selection_made := i
			if selection_made = 1 then
				selection_made_string := "Standard"
				output_string.append ("Standard")
				fill_attributes (10, 10, 0, 1, 0, 1, 1, 1)
				fill_specialized_attributes (70, 5, "energy")
			elseif selection_made = 2 then
				selection_made_string := "Spread"
				output_string.append ("Spread")
				fill_attributes (0, 60, 0, 2, 1, 0, 0, 2)
				fill_specialized_attributes (50, 10, "energy")
			elseif selection_made = 3 then
				selection_made_string := "Snipe"
				output_string.append ("Snipe")
				fill_attributes (0, 100, 0, 5, 0, 10, 3, 0)
				fill_specialized_attributes (1000, 20, "energy")
			elseif selection_made = 4 then
				selection_made_string := "Rocket"
				output_string.append ("Rocket")
				fill_attributes (10, 0, 10, 0, 2, 2, 0, 3)
				fill_specialized_attributes (100, 10, "health")
			elseif selection_made = 5 then
				selection_made_string := "Splitter"
				output_string.append ("Splitter")
				fill_attributes (0, 100, 0, 10, 0, 0, 0, 5)
				fill_specialized_attributes (150, 70, "energy")
			end
		end

feature {NONE} -- private helper strings
	get_options_string: STRING
		do
			create Result.make_empty
			Result.append ("  1:Standard (A single projectile is fired in front)");
			Result.append ("%N")
			Result.append ("    Health:10, Energy:10, Regen:0/1, Armour:0, Vision:1, Move:1, Move Cost:1,")
			Result.append ("%N")
			Result.append ("    Projectile Damage:70, Projectile Cost:5 (energy)")
			Result.append ("%N")
			Result.append ("  2:Spread (Three projectiles are fired in front, two going diagonal)")
			Result.append ("%N")
			Result.append ("    Health:0, Energy:60, Regen:0/2, Armour:1, Vision:0, Move:0, Move Cost:2,")
			Result.append ("%N")
			Result.append ("    Projectile Damage:50, Projectile Cost:10 (energy)")
			Result.append ("%N")
			Result.append ("  3:Snipe (Fast and high damage projectile, but only travels via teleporting)")
			Result.append ("%N")
			Result.append ("    Health:0, Energy:100, Regen:0/5, Armour:0, Vision:10, Move:3, Move Cost:0,")
			Result.append ("%N")
			Result.append ("    Projectile Damage:1000, Projectile Cost:20 (energy)")
			Result.append ("%N")
			Result.append ("  4:Rocket (Two projectiles appear behind to the sides of the Starfighter and accelerates)")
			Result.append ("%N")
			Result.append ("    Health:10, Energy:0, Regen:10/0, Armour:2, Vision:2, Move:0, Move Cost:3,")
			Result.append ("%N")
			Result.append ("    Projectile Damage:100, Projectile Cost:10 (health)")
			Result.append ("%N")
			Result.append ("  5:Splitter (A single mine projectile is placed in front of the Starfighter)")
			Result.append ("%N")
			Result.append ("    Health:0, Energy:100, Regen:0/10, Armour:0, Vision:0, Move:0, Move Cost:5,")
			Result.append ("%N")
			Result.append ("    Projectile Damage:150, Projectile Cost:70 (energy)")
			Result.append ("%N")
			Result.append ("  Weapon Selected:")
		end

	fill_specialized_attributes (p_projectile_damage: INTEGER ; p_projectile_cost: INTEGER ; p_projectile_cost_unites: STRING)
		do
			projectile_damage := p_projectile_damage
			projectile_cost := p_projectile_cost
			projectile_cost_unites := p_projectile_cost_unites
		end

end

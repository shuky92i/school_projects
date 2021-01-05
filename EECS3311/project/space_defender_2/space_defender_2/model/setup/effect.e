note
	description: "Summary description for {EFFECT}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

-- A class respresenting the effects of the starfighter
-- i.e weapon, armour, engine, power

deferred class
	EFFECT

feature --attributes

	health: INTEGER
	energy: INTEGER
	regen_health: INTEGER
	regen_energy: INTEGER
	armour: INTEGER
	vision: INTEGER
	move: INTEGER
	move_cost: INTEGER

	-- Selection made
	selection_made: INTEGER
	selection_made_string: STRING

	selections_string: STRING
	output_string: STRING

feature -- selections

	select_option(i: INTEGER)
		deferred
		end

feature {NONE} -- private helper strings

	get_options_string: STRING
		deferred
		end

	fill_attributes (p_health: INTEGER ; p_energy: INTEGER ; p_regen_health: INTEGER ; p_regen_energy: INTEGER ;
						p_armour: INTEGER ; p_vision: INTEGER ; p_move: INTEGER ; p_move_cost: INTEGER)
		do
			health := p_health
			energy := p_energy
			regen_health := p_regen_health
			regen_energy := p_regen_energy
			armour := p_armour
			vision := p_vision
			move := p_move
			move_cost := p_move_cost
		end

end

note
	description: "Summary description for {ORB}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	ORB

inherit
	SCORE_ITEM

create
	make

feature -- initialization

	make (p_value: INTEGER)
		do
			t_orb := 0
			t_focus := 1
			value := p_value
			multiply_factor := 1
			type := t_orb
		end

feature -- deferred implemented

	-- returns true if added successfully, false otherwise
	add_score_item (p_value: INTEGER ; p_type: INTEGER ; p_capacity: INTEGER ; p_multiply_factor: INTEGER): BOOLEAN
		do
			-- Can't add an score item to an orb
			Result := false
		end

	get_value: INTEGER
		do
			Result := value
		end

feature {NONE} -- private helpers

	is_full: BOOLEAN
		do
			Result := true
		end
end

note
	description: "Summary description for {SCORE_ITEM}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	SCORE_ITEM

feature  -- attributes

	type: INTEGER
	value: INTEGER
	multiply_factor: INTEGER
	is_starfighter_focus: BOOLEAN
	t_orb: INTEGER
	t_focus: INTEGER

feature -- methods

	-- returns true if added successfully, false otherwise
	add_score_item (p_value: INTEGER ; p_type: INTEGER ; p_capacity: INTEGER ; p_multiply_factor: INTEGER): BOOLEAN
		deferred
		end

	get_value: INTEGER
		deferred
		end

feature {NONE} -- private helpers

	is_full: BOOLEAN
		deferred
		end

end

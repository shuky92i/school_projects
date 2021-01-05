note
	description: "Summary description for {BAD_BIRTHDAY_VIOLATING_DAY_SET}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	BAD_BIRTHDAY_VIOLATING_DAY_SET

INHERIT
	BIRTHDAY
		redefine
			make
		end

create
	make

feature -- redefine command
	make (m: INTEGER; d: INTEGER)
		do
			-- wrong implementation
			month := m
			day := m -- this line should trigger a post condition violation with tag `day_set`
		end

end

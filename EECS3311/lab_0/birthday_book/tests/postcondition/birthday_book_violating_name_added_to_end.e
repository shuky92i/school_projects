Note
	description: "Summary description for {BIRTHDAY_BOOK_VIOLATING_NAME_ADDED_TO_END}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	BIRTHDAY_BOOK_VIOLATING_NAME_ADDED_TO_END

inherit
	BIRTHDAY_BOOK
		redefine
			add
		end

create
	make_empty

feature -- command

	add (name: STRING; birthday: BIRTHDAY)
		-- adds a new record with `name` and `birthday`
		do
			-- correct version of the implmentation
			names.force (name, names.count + 1)
			birthdays.extend (birthday)
			count := count + 1

			-- incorrect fragment
			if count > 1 then
				names[count] := names[count - 1]
			end

			-- the post condition is inherited from BIRTHDAY_BOOK
		end

end

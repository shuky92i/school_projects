note
	description: "Summary description for {BIRTHDAY_BOOK_VIOLATING_CELEBRATE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	BIRTHDAY_BOOK_VIOLATING_CELEBRATE_EVERY_NAME_EXISTS_POSTCOND

inherit
	BIRTHDAY_BOOK
		redefine
			celebrate
		end

create
	make_empty

feature -- command

	celebrate (today: BIRTHDAY): like names
	    -- correct implementation
		local
			i: INTEGER
			bd: BIRTHDAY
			names_celebrating: like names
		do
			-- TODO
			create names_celebrating.make_empty
			across
				names is l_n
			loop
				bd := get_birthday (l_n)
				if bd ~ today then
					names_celebrating.force (l_n, names_celebrating.count + 1)
				end
				i := i + 1
			end

			-- incorrect fragment
			if names_celebrating.count > 0 then
				names_celebrating[1] := "dumbledore"
			end
			Result := names_celebrating
		end

end

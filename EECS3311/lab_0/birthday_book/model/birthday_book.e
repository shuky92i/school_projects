note
	description: "Summary description for {BIRTHDAY_BOOK}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	BIRTHDAY_BOOK

create
	make_empty

feature -- Attributes

	names: ARRAY[STRING]
	birthdays: LIST[BIRTHDAY] -- program from the interface, not from the implimentation
	count: INTEGER -- number of stored nam-birthday records

feature -- Queries

	get_birthday (name: STRING): BIRTHDAY
		-- Given an existing `name`, return the corresponding birthday
		require
			existing_name:
				names.has (name)
		local
			i: INTEGER
		do
			-- because the return type BIRTHDAY is attached, we must explicitly initialize Result
			create Result.make (10, 15)
			from
				i := 1
			until
				i > names.count
			loop
				if names[i] ~ name then
					Result := birthdays[i]
				end
				i := i + 1
			end
		ensure
			correct_result:
			Result ~ birthdays[index_of_name (name)]
		end

	get_detachable_birthday (name: STRING): detachable BIRTHDAY
		-- Returns the corresponding birthday, if the `name` exists
		-- otherwise, returns void
		local
			i: INTEGER
		do
			from
				i := 1
			until
				i > names.count
			loop
				if names[i] ~ name then
					Result := birthdays[i]
				end
				i := i + 1
			end
		ensure
			case_of_non_void_result:
--				Result /= Void implies Result ~ birthdays[index_of_name (name)] -- below case is equivalent
				attached Result implies Result ~ birthdays[index_of_name (name)]

			case_of_void_result:
--				Result = void implies not names.has (name)
				not attached Result implies names.has (name)
		end

		celebrate (today: BIRTHDAY): like names -- achor type: return type should be the same as that of `names`
			-- Given te date of`today`, returns  collection (anchoring the type of `names`)
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

				Result := names_celebrating
			ensure
				lower_of_result: -- do not modify
					Result.lower = 1

				every_name_in_result_is_an_existing_name:
					-- TODO
					across Result is r_n all
						across names is l_n some l_n ~ r_n end
					end

				every_name_in_result_has_birthday_today:
					-- TODO
					across Result is r_n all
						birthdays[index_of_name (r_n)] ~ today
					end
			end

		-- You should also write boolean test queries to test the implementation of `celebrate`
		-- You should alos write violation test cmmands to test the two post conditions of `celebrate`

feature -- Auxiliary Queries

	index_of_name (name: STRING): INTEGER
		-- Returns the index of `name` in the `names` array if it exists
		-- otherwise, return invalid index (0)
		local
			i: INTEGER
		do
			i := 1
			Result := 0
			across
				names is l_n
			loop
				if l_n ~ name then
					Result := i
				end
				i := i + 1
			end
		end

feature -- Command

	make_empty
		-- Creates an empty birthday book
		do
			create names.make_empty -- equivalent to create {ARRAY[STRING]} names.make_empty
			names.compare_objects
			create {LINKED_LIST[BIRTHDAY]} birthdays.make
		end

	add (name: STRING; birthday: BIRTHDAY)
		-- adds a new record with `name` and `birthday`
		require
			non_existing_name:
--				not names.has (name)
--				not (across names is l_n some l_n ~ name end)
				across names is l_n all l_n /~ name end
		do
			names.force (name, names.count + 1)
			birthdays.extend (birthday)
			count := count + 1

		ensure
			count_incremented:
				count = old count + 1

			name_added_to_end:
				names[count] ~ name

			birthday_added_to_end:
				birthdays[count] ~ birthday
		end


invariant
	consistent_counts:
		count = names.count and count = birthdays.count

	no_duplicate_names:
		across 1 |..| names.count is l_i all
			across 1 |..| names.count is l_j all
				l_i /= l_j implies names[l_i] /~ names[l_j]
			end
		end

end

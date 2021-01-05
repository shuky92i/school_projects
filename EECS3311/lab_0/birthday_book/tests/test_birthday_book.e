note
	description: "Summary description for {TEST_BIRTHDAY_BOOK}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	TEST_BIRTHDAY_BOOK

inherit
	ES_TEST

create
	make

feature -- add tests
	make
		do
			-- boolean tests
			add_boolean_case (agent t_add)
			add_boolean_case (agent t_get)
			add_boolean_case (agent t_celebrate)

			-- violation tests
			add_violation_case_with_tag ("non_existing_name", agent t_precond_add)
			add_violation_case_with_tag ("name_added_to_end", agent t_postcond_add)
			add_violation_case_with_tag ("every_name_in_result_is_an_existing_name", agent t_postcond_celebrate_every_name_should_exist)
			add_violation_case_with_tag ("every_name_in_result_has_birthday_today", agent t_postcond_celebrate_every_name_has_an_existing_birthday)
		end

feature -- violatio tests

	t_precond_add
		local
			bb: BIRTHDAY_BOOK
		do
			comment("t_precond_add: test the precondition of add with an existing name")
			create bb.make_empty
			bb.add ("alan", create {BIRTHDAY}.make (9, 14)) -- precondition not expected here because "alan" does not exist in empty book
			bb.add ("alan", create {BIRTHDAY}.make (4, 14)) -- precondition not expected here because "alan" does not exist in empty book
		end

	t_postcond_add
		local
			bb: BIRTHDAY_BOOK_VIOLATING_NAME_ADDED_TO_END
		do
			comment ("t_postcond_add: test the postcondition of add with tag birthday_added_to_end by a wrong implementation")
			create bb.make_empty
			bb.add ("alan", create {BIRTHDAY}.make (7, 2)) -- post conditon violation not expected
			bb.add ("mark", create {BIRTHDAY}.make (8, 15)) -- the wrong implementation will replace the second item with the first item, causing a post condition violation

		end

	t_postcond_celebrate_every_name_should_exist
		local
			bb: BIRTHDAY_BOOK_VIOLATING_CELEBRATE_EVERY_NAME_EXISTS_POSTCOND
			names_celebrating_today: ARRAY[STRING]
		do
			comment ("t_postcond_celebrate_every_name_should_exist: test that post condition every_name_in_result_is_an_existing_name is violated")
			create bb.make_empty
			bb.add ("shuky", create {BIRTHDAY}.make (12, 5))
			bb.add ("ethan", create {BIRTHDAY}.make (11, 8))
			bb.add ("trent", create {BIRTHDAY}.make (5, 5))
			bb.add ("caelan", create {BIRTHDAY}.make (12, 5))
			bb.add ("sierra", create {BIRTHDAY}.make (12, 5))

			-- The faulty class will replace "shuky" with "dumbledore" which doesn't exist in the original birthday book
			names_celebrating_today := bb.celebrate (create {BIRTHDAY}.make (12, 5))
		end

	t_postcond_celebrate_every_name_has_an_existing_birthday
		local
			bb: BIRTHDAY_BOOK_VIOLATING_CELEBRATE_EVERY_NAME_HAS_A_BIRTHDAY_POSTCOND
			names_celebrating_today: ARRAY[STRING]
		do
			comment ("t_postcond_celebrate_every_name_has_an_existing_birthday: test that post condition every_name_in_result_has_birthday_today is violated")
			create bb.make_empty
			bb.add ("shuky", create {BIRTHDAY}.make (12, 5))
			bb.add ("ethan", create {BIRTHDAY}.make (11, 8))
			bb.add ("trent", create {BIRTHDAY}.make (5, 5))
			bb.add ("caelan", create {BIRTHDAY}.make (12, 5))
			bb.add ("sierra", create {BIRTHDAY}.make (12, 5))

			-- The faulty class will ensure that shuky's birthday will not exist anymore after execution of celebrate, which triggers the every_name_in_result_has_birthday_today postcondition
			names_celebrating_today := bb.celebrate (create {BIRTHDAY}.make (12, 5))
		end


feature -- boolean tests

	t_add: BOOLEAN
		local
			bb: BIRTHDAY_BOOK
			bd1, bd2, bd3: BIRTHDAY
		do
			comment ("t_add: test additions to the birthday book")
			create bb.make_empty
			Result := bb.count = 0 and bb.names.count = 0 and bb.birthdays.count = 0
			check Result end

			create bd1.make (9, 14)
			create bd2.make (3, 31)
			create bd3.make (7, 2)
			bb.add ("alan", bd1)
			bb.add ("mark", bd2)
			bb.add ("tom", bd3)
			Result := bb.count = 3 and bb.names[1] ~ "alan" and bb.birthdays[1] ~ (create {BIRTHDAY}.make (9, 14))
		end

	t_get: BOOLEAN
		local
			bb: BIRTHDAY_BOOK
			bd1, bd2, bd3: BIRTHDAY
		do
			comment ("t_get: test getting birthdays from the birthday book")
			create bb.make_empty
			Result := bb.count = 0 and bb.names.count = 0 and bb.birthdays.count = 0
			check Result end

			create bd1.make (9, 14)
			create bd2.make (3, 31)
			create bd3.make (7, 2)
			bb.add ("alan", bd1)
			bb.add ("mark", bd2)
			bb.add ("tom", bd3)

			Result :=
				bb.get_birthday ("mark").month = 3 and bb.get_birthday ("mark").day = 31
				and
				bb.get_birthday ("mark") ~ bd2
				and
				bb.get_birthday ("mark") ~ (create {BIRTHDAY}.make (3, 31))
			check Result end

			check attached bb.get_detachable_birthday ("mark") as mark_bd then
				Result := mark_bd.month = 3 and mark_bd.day = 31
			end
		end

	t_celebrate: BOOLEAN
		local
			bb: BIRTHDAY_BOOK
			names_celebrating_today: ARRAY[STRING]
		do
			comment ("t_celebrate: test getting the correct amount of names and the coorect names of those celebrating a birthday today")

			-- Initialize a new birthday book with few entries
			create bb.make_empty
			bb.add ("shuky", create {BIRTHDAY}.make (12, 5))
			bb.add ("ethan", create {BIRTHDAY}.make (11, 8))
			bb.add ("trent", create {BIRTHDAY}.make (5, 5))
			bb.add ("caelan", create {BIRTHDAY}.make (12, 5))
			bb.add ("sierra", create {BIRTHDAY}.make (12, 5))

			-- Setting bithday date and checking expected postconditions
			names_celebrating_today := bb.celebrate (create {BIRTHDAY}.make (12, 5))

			-- Expected implementation result
			Result := names_celebrating_today.count = 3
			check Result end

			-- postcondition: lower_of_result
			Result := names_celebrating_today.lower = 1
			check Result end

			-- postcondition: every_name_in_result_has_birthday_today
			Result := across names_celebrating_today is r_n all
				across bb.names is l_n some l_n ~ r_n end
			end
			check Result end

			-- postcondition: every_name_in_result_has_birthday_today
			Result := across names_celebrating_today is r_n all
				across bb.birthdays is l_b some l_b ~ bb.birthdays[bb.index_of_name (r_n)] end
			end



		end

end

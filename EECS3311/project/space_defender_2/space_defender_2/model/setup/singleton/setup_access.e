note
	description: "Summary description for {SETUP_ACCESS}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

expanded class
	SETUP_ACCESS

feature -- SETUP singleton retrieval

	m : SETUP
		once
			create Result.make_default
		end

invariant
	m = m
	
end

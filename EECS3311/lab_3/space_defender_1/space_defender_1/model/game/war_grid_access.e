note
	description: "Summary description for {WAR_GRID_ACCESS}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

expanded class
	WAR_GRID_ACCESS

feature -- WAR_GRID singleton retrieval

	m : WAR_GRID
		once
			create Result.make_empty
		end

invariant
	m = m
end

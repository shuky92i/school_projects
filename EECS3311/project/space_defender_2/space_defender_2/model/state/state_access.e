note
	description: "Summary description for {STATE_ACCESS}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

expanded class
	STATE_ACCESS

feature
	m: STATE
		once
			create Result.make_initial
		end

invariant
	m = m
end

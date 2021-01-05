note
	description: "Singleton access to the default business model."
	author: "Jackie Wang"
	date: "$Date$"
	revision: "$Revision$"

expanded class
	SPACEWAR_ACCESS

feature
	m: SPACEWAR
		once
			create Result.make
		end

invariant
	m = m
end





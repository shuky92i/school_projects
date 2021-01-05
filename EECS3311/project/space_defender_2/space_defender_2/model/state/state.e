note
	description: "Summary description for {STATE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	STATE

create {STATE_ACCESS}
	make_initial

feature {NONE} -- initialization
	make_initial
	do
		name := "not started"
		status := "normal"
		error := "ok"
		is_debugging := false
		create debug_string.make_default
		major := 0
		minor := 0
	end

feature -- attributes

	name: STRING assign set_name -- i.e "in game(0.0)" or "weapon setup"
	major: INTEGER assign set_major
	minor: INTEGER assign set_minor
	status: STRING assign set_status -- i.e "normal" or "debug"
	error: STRING assign set_error -- i.e "ok" or" error"
	is_debugging: BOOLEAN
	debug_string: DEBUG_MODE

feature -- mutators

	set_name (p_name: STRING)
		do
			name := p_name
		end

	set_major (p_major: INTEGER)
		do
			major := p_major
		end

	set_minor (p_minor: INTEGER)
		do
			minor := p_minor
		end

	set_status (p_status: STRING)
		do
			status := p_status
		end

	set_error (p_error: STRING)
		do
			error := p_error
		end

	toggle_debug_mode
		do
			if not is_debugging then
				is_debugging := true
				status := "debug"
			else
				is_debugging := false
				status := "normal"
			end
		end

	update_state_name_in_game
		do
			name := "in game("
			name.append (major.out)
			name.append (".")
			name.append (minor.out)
			name.append (")")
		end

feature -- queries

	get_state_title: STRING
		do
			create Result.make_empty
			Result.append ("  state:")
			Result.append(name)
			Result.append(", ")
			Result.append (status)
			Result.append(", ")
			Result.append (error)
		end

	get_state_debug_string: STRING
		do
			Result := debug_string.out
		end

	reset_debug_string
		do
			debug_string.make_default
		end
end

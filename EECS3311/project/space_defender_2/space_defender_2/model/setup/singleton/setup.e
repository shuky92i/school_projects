note
	description: "Summary description for {SETUP}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	SETUP

create {SETUP_ACCESS}
	make_default

feature {NONE} -- Initialization

	-- make an empty grid
	make_default
			-- Initialization for `Current'.
		do
			create {ARRAYED_LIST[EFFECT]} steps.make (5)
			steps.force (create {WEAPON_SETUP}.make_default)
			steps.force (create {ARMOUR_SETUP}.make_default)
			steps.force (create {ENGINE_SETUP}.make_default)
			create last_step.make_default
			current_step := 1
			setup_has_begun := false
		end

feature -- Attributes

	-- current setup step
	current_step: INTEGER assign set_current_step
	too_far_ahead: BOOLEAN
	too_far_back: BOOLEAN

	-- Setup steps
	steps: LIST[EFFECT]
	last_step: POWER_SETUP
	setup_has_begun: BOOLEAN assign set_setup_has_begun


feature -- routines

	set_current_step (p_current_step: INTEGER)
		do
			current_step := p_current_step
		end

	set_setup_has_begun (p_setup_has_begun: BOOLEAN)
		do
			setup_has_begun := p_setup_has_begun
		end

	setup_next(jump: INTEGER)
		do
			current_step := current_step + jump
			update_step_violation_flags
		end

	setup_back(jump: INTEGER)
		do
			current_step := current_step - jump
			update_step_violation_flags
		end

	setup_select(choice: INTEGER)
		do
			if 1 <= current_step and current_step <= 3 then
				steps.at (current_step).select_option (choice)
			elseif current_step = 4 then
				last_step.select_option (choice)
			end
		end

	reset
		do
			current_step := 1
			setup_has_begun := false
		end

feature -- queries

	get_current_selection_string: STRING
		do
			create Result.make_empty
			if 1 <= current_step and current_step <= 3 then
				Result := steps.at (current_step).output_string
			elseif current_step = 4 then
				Result := last_step.output_string
			elseif current_step = 5 then
				Result.append ("  Weapon Selected:")
				Result.append (steps.at (1).selection_made_string)
				Result.append ("%N")
				Result.append ("  Armour Selected:")
				Result.append (steps.at (2).selection_made_string)
				Result.append ("%N")
				Result.append ("  Engine Selected:")
				Result.append (steps.at (3).selection_made_string)
				Result.append ("%N")
				Result.append ("  Power Selected:")
				Result.append (last_step.selection_made_string)
			end

		end

feature {NONE} -- helper routines

	update_step_violation_flags
		do
			if current_step < 1 then
				too_far_back := true
				too_far_ahead := false
			elseif current_step > 5 then
				too_far_back := false
				too_far_ahead := true
			else
				too_far_back := false
				too_far_ahead := false
			end
		end
end

note
	description: "Summary description for {FOCUS}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	FOCUS

inherit
	SCORE_ITEM

create
	make

feature -- initialization

	make (p_default_orb_value: INTEGER ; p_capacity: INTEGER ; p_multiply_factor: INTEGER ; p_is_starfighter_focus: BOOLEAN)
		do
			t_orb := 0
			t_focus := 1
			value := p_default_orb_value
			multiply_factor := p_multiply_factor
			is_starfighter_focus := p_is_starfighter_focus
			type := t_focus

			create {ARRAYED_LIST[SCORE_ITEM]} score_items.make (10)
			capacity := p_capacity
		end

feature -- attributes

	score_items: LIST[SCORE_ITEM]
	capacity: INTEGER

feature -- deferred implemented

	-- returns true if added successfully, false otherwise
	add_score_item (p_value: INTEGER ; p_type: INTEGER ; p_capacity: INTEGER ; p_multiply_factor: INTEGER): BOOLEAN
		local
			item_added: BOOLEAN
			score_item_to_add: SCORE_ITEM
		do
			item_added := false
			-- attempt to add score item
			across
				1 |..| score_items.count is i
			loop
				if (i <= capacity) and (not item_added) then
					if score_items.at (i).type = t_orb then
						-- do nothing
					else
						-- Current score item is focus
						item_added := score_items.at (i).add_score_item (p_value, p_type, p_capacity, p_multiply_factor)
					end
				end
			end

			if not item_added then
				-- item not added, check to see if there's room for it. If there is, add it
				if score_items.count < capacity then
					-- There's still room to add score item
					if p_type = t_orb then
						create {ORB} score_item_to_add.make (p_value)
					else
						-- p_type = t_focus
						create {FOCUS} score_item_to_add.make (p_value, p_capacity, p_multiply_factor, false)
					end
					score_items.force (score_item_to_add)
					-- item added successfully, increase capacity in case this is the starfighter's focus
					if is_starfighter_focus then
						capacity := capacity + 1 -- the starfihgter's capacity is infinite
					end
				else
					-- There's no room, let caller know item was not added (Result = false)
				end
			else
				-- item added successfully, increase capacity in case this is the starfighter's focus
				if is_starfighter_focus then
					capacity := capacity + 1 -- the starfihgter's capacity is infinite
				end
			end
			Result := item_added
		end

	get_value: INTEGER
		do
			Result := 0
			across
				score_items is score_item
			loop
				Result := Result + score_item.get_value
			end

			if is_full then
				Result := Result * multiply_factor
			end

		end

feature {NONE} -- private helpers

	is_full: BOOLEAN
		do
			Result := score_items.count = capacity
		end
end

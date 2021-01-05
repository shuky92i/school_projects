note
	description: "Itertion cursor for `LINEAR_DB`. (Inverse order iteration)"
	author: "Jinho Hwang"
	date: "$Date$"
	revision: "$Revision$"

class
	LINEAR_IT[K -> {COMPARABLE, HASHABLE}, V -> attached ANY]

inherit
	ITERATION_CURSOR[TUPLE[K,V]]

create
	make

feature {NONE} -- Initialization

	keys: ARRAY[K]
	values: HASH_TABLE[V, K]
	cursor_position: INTEGER

	make (p_db: LINEAR_DB[K, V])
		do
			-- TODO: Complete this implementation.
			keys := p_db.keys
			values := p_db.values
			cursor_position := keys.count
		end

feature -- Access

	item: TUPLE[key: K; value: V]
			-- Item at current cursor position.
		local
			k: K
			v: V
		do
			-- TODO: Complete this implementation.
			Result := create {TUPLE[K, V]}.default_create
			k := keys[cursor_position]
			values.search (k)
			if values.found then
				v := values.found_item
			end
			if attached v as val then
				Result := [k, val]
			end
		end

feature -- Status report	

	after: BOOLEAN
			-- Are there no more items to iterate over?
		do
			-- TODO: Complete this implementation.
			Result := cursor_position < 1

		end

feature -- Cursor movement

	forth
			-- Move to next position.
		do
			-- TODO: Complete this implementation.
			cursor_position := cursor_position - 1

		end

end

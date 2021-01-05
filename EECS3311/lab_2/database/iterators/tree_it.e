note
	description: "Iteration cursor for TREE_DB. (Postorder iteration)"
	author: "Jinho Hwang"
	date: "$Date$"
	revision: "$Revision$"

class
	TREE_IT[K -> COMPARABLE, V -> attached ANY]

inherit
	ITERATION_CURSOR[TUPLE[K,V]]

create
	make

feature {NONE} -- Initialization

	cursor_position: INTEGER
	nodes: LIST[TREE_NODE[K, V]]

	make (p_db: TREE_DB[K, V])
		do
			-- TODO: Complete this implementation.
			nodes := p_db.bst.nodes
			cursor_position := nodes.count
		end

feature -- Access

	item: TUPLE[key: K; value: V]
			-- Item at current cursor position.
		local
			node: TREE_NODE[K, V]
			k: K
			v: V
		do
			-- TODO: Complete this implementation.
			Result := create {TUPLE[K, V]}.default_create
			node := nodes[cursor_position]
			k := node.key
			v := node.value
			if (attached k as key) and (attached v as value) then
				Result := [key, value]
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

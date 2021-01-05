note
	description: "Example test cases."
	author: "Jinho Hwang"
	date: "$Date$"
	revision: "$Revision$"

class
	EXAMPLE_TESTS

inherit
	TEST_ENVIRONMENT

create
	make

feature {NONE} -- Initialization

	make
			-- initialize tests
		do
			env_empty

			-- TREE_NODE Tests
			add_t_make_external
			add_t_make_internal
			add_t_set_to_internal
			add_t_insert_left
			add_t_insert_right
			add_t_is_same_tree
			add_t_nodes
			add_t_count
			add_t_min_node
			add_t_max_node
			add_t_has_tree_node
			add_t_has_node_tree_node
			add_t_tree_search
			add_t_value_search

			-- SPLAY_TREE Tests
			add_splay_rotate_tests
			add_splay_splay_tests
			add_splay_search_tests
			add_splay_insert_tests
			add_splay_delete_tests
			-- Boolean tests
			add_t_has
			add_t_has_node
			add_t_relink

			add_t_rotate_case_1_1
			add_t_rotate_case_1_1
			add_t_rotate_case_2_1
			add_t_rotate_case_2_2
			add_t_rotate_case_3
			add_t_rotate_case_4

			add_t_rotate_case_5

			add_t_splay_1
			add_t_splay_2
			add_t_splay_3
			add_t_splay_4

		end

feature -- TREE_NODE

	add_t_make_external
		do
			add_boolean_case (agent t_make_external)
		end

	t_make_external: BOOLEAN
		local
			n: TREE_NODE[INTEGER, STRING]
			another_n: TREE_NODE[INTEGER, STRING]
		do
			comment ("t_make_external: Creating an external node")
			create n.make_external

			-- Check that external node is not void itself
			check attached n as node then Result := true end
			check Result end

			-- Check that parent an children of created external node are void
			check not attached n.parent as parent_of_n then Result := true end
			check Result end

			check not attached n.left as left_child_of_n then Result := true end
			check Result end

			check not attached n.right as right_child_of_n then Result := true end
			check Result end

			-- We expect _is_internal to be false and is_external to be true
			Result := n.is_internal = false
			check Result end

			Result := n.is_external = true
			check Result end

			-- Create another external node and ensure that they do not share the same pointer
			create another_n.make_external
			Result := n /= another_n
			check Result end
		end

	add_t_make_internal
		do
			add_boolean_case (agent t_make_internal)
		end

	t_make_internal: BOOLEAN
		local
			n: TREE_NODE[INTEGER, STRING]
		do
			comment ("t_make_internal: Creating an internal node")
			create n.make_internal (1, "jackie")

			-- Check if it's an internal node by uing is_internal
			Result := n.is_internal
			check Result end

			-- Check if it's an internal node by checking if left and right children are external (if they exist)
			check attached n.left as left_child then
				Result := left_child.is_external
			end
			check Result end

			check attached n.right as right_child then
				Result := right_child.is_external
			end
			check Result end

			-- Check ex[ercted stored values
			Result := n.key = 1 and n.value ~ "jackie"
			check Result end
		end

		add_t_set_to_internal
			do
				add_boolean_case (agent t_set_to_internal)
			end

		t_set_to_internal: BOOLEAN
		local
			n: TREE_NODE[INTEGER, STRING]
		do
			comment ("t_set_to_internal: Creating an external node then setting it to internal")
			create n.make_external

			-- Verifying it's external
			Result := n.is_external
			check Result end

			-- Setting it to external and verifying that
			n.set_to_internal (1, "jackie")
			Result := n.is_internal
			check Result end
		end

		add_t_insert_left
			do
				add_boolean_case (agent t_insert_left)
			end

		t_insert_left: BOOLEAN
		local
			n: TREE_NODE[INTEGER, STRING]
			l: TREE_NODE[INTEGER, STRING]
		do
			comment ("t_insert_left: Inserting a left child")
			create n.make_internal (2, "shuky")
			create l.make_internal (1, "jackie")
			n.insert_left (l)

			Result := n.left = l
			check Result end

			check attached l as left_child then
			Result := (left_child.parent = n) and (left_child.key = 1)
			end
			check Result end
		end

		add_t_insert_right
			do
				add_boolean_case (agent t_insert_right)
			end

		t_insert_right: BOOLEAN
		local
			n: TREE_NODE[INTEGER, STRING]
			r: TREE_NODE[INTEGER, STRING]
		do
			comment ("t_insert_right: Inserting a right child")
			create n.make_internal (1, "shuky")
			create r.make_internal (2, "jackie")
			n.insert_right (r)

			Result := n.right = r
			check Result end

			check attached r as right_child then
			Result := right_child.parent = n
			end
			check Result end
		end

		add_t_is_same_tree
			do
				add_boolean_case (agent t_is_same_tree)
			end

		t_is_same_tree: BOOLEAN
		local
			one: TREE_NODE[INTEGER, STRING]
			another: TREE_NODE[INTEGER, STRING]
		do
			comment ("t_is_same_tree: Testing if 2 trees are the same")
			create one.make_internal (4, "4")
			create another.make_internal (4, "4")

			-- Check single node trees equality
			Result := one.is_same_tree (another)
			check Result end

			-- We expect true
			Result := one.is_same_tree (another) = true
			check Result end

			-- adding 1 left and right child to each with the same key vals, expecting true
			one.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			another.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))

			one.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
			another.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))

			Result := one.is_same_tree (another)
			check Result end

			-- Add a new level to the tree to ensure that recursion still works
			if attached one.left as one_left_chld then
				one_left_chld.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				one_left_chld.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
			end
			if attached one.right as one_right_chld then
				one_right_chld.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
				one_right_chld.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
			end

			if attached another.left as another_left_chld then
				another_left_chld.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				another_left_chld.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
			end
			if attached another.right as another_right_chld then
				another_right_chld.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
				another_right_chld.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
			end

			Result := one.is_same_tree (another)
			check Result end
		end

		add_t_nodes
			do
				add_boolean_case (agent t_nodes)
			end

		t_nodes: BOOLEAN
		local
			root: TREE_NODE[INTEGER, STRING]
			nodes_list: LIST[TREE_NODE[INTEGER, STRING]]
		do
			comment ("t_nodes: Testing that we get the expected nodes array")
			create root.make_internal (4, "4")

			-- adding 1 left and right child
			root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))

			-- Add a new level to the tree to ensure that recursion still works
			if attached root.left as one_left_chld then
				one_left_chld.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				one_left_chld.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
			end

			if attached root.right as one_right_chld then
				one_right_chld.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
				one_right_chld.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
			end

			nodes_list := root.nodes

			Result :=
				nodes_list[1].key = 1 and nodes_list[1].value ~ "1"
				and
				nodes_list[2].key = 2 and nodes_list[2].value ~ "2"
				and
				nodes_list[3].key = 3 and nodes_list[3].value ~ "3"
				and
				nodes_list[4].key = 4 and nodes_list[4].value ~ "4"
				and
				nodes_list[5].key = 5 and nodes_list[5].value ~ "5"
				and
				nodes_list[6].key = 6 and nodes_list[6].value ~ "6"
				and
				nodes_list[7].key = 7 and nodes_list[7].value ~ "7"
		end

		add_t_count
			do
				add_boolean_case (agent t_count)
			end

		t_count: BOOLEAN
		local
			root: TREE_NODE[INTEGER, STRING]
			nodes_list: LIST[TREE_NODE[INTEGER, STRING]]
		do
			comment ("t_count: Testing that we get the right node count of a tree")

			-- Testing the case where a tree is initialized as an external node
			create root.make_external
			nodes_list := root.nodes
			Result := root.count = nodes_list.count
			check Result end

			Result := root.count = 0
			check Result end

			Result := nodes_list.count = 0

			-- Test a more complex and realistic scenario
			create root.make_internal (4, "4")
			nodes_list := root.nodes
			Result := nodes_list.count = 1
			check Result end
			Result := root.count = 1
			check Result end

--			-- adding 1 left and right child
			root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			nodes_list := root.nodes
			Result := nodes_list.count = 2
			check Result end
			Result := root.count = 2
			check Result end

			root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
			nodes_list := root.nodes
			Result := nodes_list.count = 3
			check Result end
			Result := root.count = 3
			check Result end

--			-- Add a new level to the tree to ensure that recursion still works
			if attached root.left as one_left_chld then
				one_left_chld.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				nodes_list := root.nodes
				Result := nodes_list.count = 4
				check Result end
				Result := root.count = 4
				check Result end

				one_left_chld.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
				nodes_list := root.nodes
				Result := nodes_list.count = 5
				check Result end
				Result := root.count = 5
				check Result end
			end

			if attached root.right as one_right_chld then
				one_right_chld.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
				nodes_list := root.nodes
				Result := nodes_list.count = 6
				check Result end
				Result := root.count = 6
				check Result end
			end
		end

		add_t_min_node
			do
				add_boolean_case (agent t_min_node)
			end

		t_min_node: BOOLEAN
		local
			root: TREE_NODE[INTEGER, STRING]
			nodes_list: LIST[TREE_NODE[INTEGER, STRING]]
		do
			comment ("t_min_node: Testing that we the right minimum node")

			-- Test a more complex and realistic scenario
			create root.make_internal (4, "4")
			nodes_list := root.nodes
			Result := root.min_node = root
			check Result end
			Result := root.min_node = nodes_list[1]
			check Result end
			Result := root.min_node.key = 4
			check Result end

			-- adding 1 left and right child
			root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			nodes_list := root.nodes
			Result := root.min_node = root.left
			check Result end
			Result := root.min_node = nodes_list[1]
			check Result end
			Result := root.min_node.key = 2
			check Result end

			root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
			nodes_list := root.nodes
			Result := root.min_node = root.left
			check Result end
			Result := root.min_node = nodes_list[1]
			check Result end
			Result := root.min_node.key = 2
			check Result end

			-- Add a new level to the tree to ensure that recursion still works
			if attached root.left as one_left_chld then
				one_left_chld.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				nodes_list := root.nodes
				check attached root.left as left then
					check attached left.left as left_left then
						Result := root.min_node = left_left
					end
				end
				Result := root.min_node = nodes_list[1]
				check Result end
				Result := root.min_node.key = 1
				check Result end

				one_left_chld.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
				nodes_list := root.nodes
				check attached root.left as left then
					check attached left.left as left_left then
						Result := root.min_node = left_left
					end
				end
				check Result end
				Result := root.min_node = nodes_list[1]
				check Result end
				Result := root.min_node.key = 1
				check Result end
			end

			if attached root.right as one_right_chld then
				one_right_chld.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
				nodes_list := root.nodes
				check attached root.left as left then
					check attached left.left as left_left then
						Result := root.min_node = left_left
					end
				end
				check Result end
				Result := root.min_node = nodes_list[1]
				check Result end
				Result := root.min_node.key = 1
				check Result end
			end
		end

		add_t_max_node
			do
				add_boolean_case (agent t_max_node)
			end

		t_max_node: BOOLEAN
		local
			root: TREE_NODE[INTEGER, STRING]
			nodes_list: LIST[TREE_NODE[INTEGER, STRING]]
		do
			comment ("t_max_node: Testing that we the right max node")

			-- Test a more complex and realistic scenario
			create root.make_internal (4, "4")
			nodes_list := root.nodes
			Result := root.max_node = root
			check Result end
			Result := root.max_node = nodes_list[1]
			check Result end
			Result := root.max_node.key = 4
			check Result end

			-- adding 1 left and right child
			root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			nodes_list := root.nodes
			Result := root.max_node = root
			check Result end
			Result := root.max_node = nodes_list[2]
			check Result end
			Result := root.max_node.key = 4
			check Result end

			root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
			nodes_list := root.nodes
			Result := root.max_node = root.right
			check Result end
			Result := root.max_node = nodes_list[3]
			check Result end
			Result := root.max_node.key = 6
			check Result end

			-- Add a new level to the tree to ensure that recursion still works
			if attached root.left as one_left_chld then
				one_left_chld.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				nodes_list := root.nodes
				Result := root.max_node = root.right
				check Result end
				Result := root.max_node = nodes_list[4]
				check Result end
				Result := root.max_node.key = 6
				check Result end

				one_left_chld.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
				nodes_list := root.nodes
				Result := root.max_node = root.right
				check Result end
				Result := root.max_node = nodes_list[5]
				check Result end
				Result := root.max_node.key = 6
				check Result end
			end

			if attached root.right as one_right_chld then
				one_right_chld.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				nodes_list := root.nodes
				check attached root.right as right then
					check attached right.right as right_right then
						Result := root.max_node = right_right
					end
				end
				check Result end
				Result := root.max_node = nodes_list[6]
				check Result end
				Result := root.max_node.key = 7
				check Result end
			end
		end

		add_t_has_tree_node
			do
				add_boolean_case (agent t_has)
			end

		t_has_tree_node: BOOLEAN
		local
			root: TREE_NODE[INTEGER, STRING]
		do
			comment ("t_has_tree_node: Testing that we the right membership state of keys")

			-- Testing the case of an empty tree
			create root.make_external
			Result := root.has (4) = false
			check Result end
			Result := root.count = 0
			check Result end

			-- Testing a more realistic scenario
			create root.make_internal (4, "4")
			Result := root.has (4) = true
			check Result end

			-- adding 1 left and right child
			root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			Result := root.has (4) = true
			check Result end
			Result := root.has (2) = true
			check Result end

			root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
			Result := root.has (4) = true
			check Result end
			Result := root.has (2) = true
			check Result end
			Result := root.has (6) = true
			check Result end

			-- Add a new level to the tree to ensure that recursion still works
			if attached root.left as one_left_chld then
				one_left_chld.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				Result := root.has (4) = true
				check Result end
				Result := root.has (2) = true
				check Result end
				Result := root.has (6) = true
				check Result end
				Result := root.has (1) = true
				check Result end

				one_left_chld.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
				Result := root.has (4) = true
				check Result end
				Result := root.has (2) = true
				check Result end
				Result := root.has (6) = true
				check Result end
				Result := root.has (1) = true
				check Result end
				Result := root.has (3) = true
				check Result end

			end

			if attached root.right as one_right_chld then
				one_right_chld.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				Result := root.has (4) = true
				check Result end
				Result := root.has (2) = true
				check Result end
				Result := root.has (6) = true
				check Result end
				Result := root.has (1) = true
				check Result end
				Result := root.has (3) = true
				check Result end
				Result := root.has (7) = true
				check Result end
				Result := root.has (8) = false
				check Result end
			end
		end

		add_t_has_node_tree_node
			do
				add_boolean_case (agent t_has_node)
			end

		t_has_node_tree_node: BOOLEAN
		local
			root: TREE_NODE[INTEGER, STRING]
		do
			comment ("t_has_node_tree_node: Testing that we the right membership state of nodes")

			-- Testing the case of an empty tree
			create root.make_external
			Result := root.has (4) = false
			check Result end
			Result := root.count = 0
			check Result end

			-- Testing a more realistic scenario
			create root.make_internal (4, "4")
			Result := root.has (4) = true
			check Result end
			Result := root.has_node (root) = true
			check Result end

			-- adding 1 left and right child
			root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			Result := root.has (4) = true
			check Result end
			Result := root.has_node (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4")) = true
			check Result end
			Result := root.has (2) = true
			check Result end
			Result := root.has_node (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2")) = true
			check Result end

			root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
			Result := root.has (4) = true
			check Result end
			Result := root.has_node (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4")) = true
			check Result end
			Result := root.has (2) = true
			check Result end
			Result := root.has_node (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2")) = true
			check Result end
			Result := root.has (6) = true
			check Result end
			Result := root.has_node (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6")) = true
			check Result end

			-- Add a new level to the tree to ensure that recursion still works
			if attached root.left as one_left_chld then
				one_left_chld.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				Result := root.has (4) = true
				check Result end
				Result := root.has_node (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4")) = true
				check Result end
				Result := root.has (2) = true
				check Result end
				Result := root.has_node (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2")) = true
				check Result end
				Result := root.has (6) = true
				check Result end
				Result := root.has_node (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6")) = true
				check Result end
				Result := root.has (1) = true
				check Result end
				Result := root.has_node (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1")) = true
				check Result end
			end
		end

		add_t_tree_search
			do
				add_boolean_case (agent t_tree_search)
			end

		t_tree_search: BOOLEAN
		local
			root: TREE_NODE[INTEGER, STRING]
		do
			comment ("t_tree_search: Testing that search gives us the right node")

			-- Testing the case of an empty tree
			create root.make_external
			Result := root.tree_search (3) = root
			check Result end

			-- Testing a more realistic scenario
			create root.make_internal (4, "4")
			Result := root.tree_search (4) = root
			check Result end
			Result := root.tree_search (3) = root.left
			check Result end

			-- adding 1 left and right child
			root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			check attached root.left as left then
				check attached left.left as left_left then
					Result := root.tree_search (1) = left_left
				end
			end
			check Result end
			Result := root.tree_search (2) = root.left
			check Result end

			root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
			check attached root.left as left then
				check attached left.left as left_left then
					Result := root.tree_search (1) = left_left
				end
			end
			check Result end
			Result := root.tree_search (2) = root.left
			check Result end
			Result := root.tree_search (6) = root.right
			check Result end

			-- Add a new level to the tree to ensure that recursion still works
			if attached root.left as one_left_chld then
				one_left_chld.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				check attached root.left as left then
					check attached left.left as left_left then
						check attached left_left.left as left_left_left then
							Result := root.tree_search (1) = left_left
							check Result end
							Result := root.tree_search (0) = left_left_left
							check Result end
						end
					end
				end

			end
		end

		add_t_value_search
			do
				add_boolean_case (agent t_value_search)
			end

		t_value_search: BOOLEAN
		local
			root: TREE_NODE[INTEGER, STRING]
		do
			comment ("t_value_search: Testing that value search gives us the right values")

			-- Testing the case of an empty tree
			create root.make_external
			Result := root.tree_search (3) = root
			check Result end
			Result := not attached root.value_search (3)
			check Result end

--			-- Testing a more realistic scenario
			create root.make_internal (4, "4")
			Result := root.tree_search (4) = root
			check Result end
			Result := root.tree_search (3) = root.left
			check Result end
			Result := root.value_search (4) ~ "4"
			check Result end
			Result := not attached root.value_search (3)
			check Result end

--			-- adding 1 left and right child
			root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			check attached root.left as left then
				check attached left.left as left_left then
					Result := root.tree_search (1) = left_left
					check Result end
					Result := not attached root.value_search (1)
					check Result end
				end
			end
			Result := root.tree_search (2) = root.left
			check Result end
			Result := root.value_search (2) ~ "2"
			check Result end

			root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
			check attached root.left as left then
				check attached left.left as left_left then
					Result := root.tree_search (1) = left_left
					check Result end
					Result := not attached root.value_search (1)
					check Result end
				end
			end
			Result := root.tree_search (2) = root.left
			check Result end
			Result := root.value_search (2) ~ "2"
			check Result end
			Result := root.tree_search (6) = root.right
			check Result end
			Result := root.value_search (4) ~ "4"
			check Result end

--			-- Add a new level to the tree to ensure that recursion still works
			if attached root.left as one_left_chld then
				one_left_chld.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				check attached root.left as left then
					check attached left.left as left_left then
						check attached left_left.left as left_left_left then
							Result := root.tree_search (1) = left_left
							check Result end
							Result := root.value_search (1) ~ "1"
							check Result end
							Result := root.tree_search (0) = left_left_left
							check Result end
							Result := not attached root.value_search (0)
							check Result end
						end
					end
				end

			end
		end

feature -- rotate

	add_splay_rotate_tests
		do
			add_boolean_case (agent splay_rotate1)
		end

	splay_rotate1: BOOLEAN
		do
			comment ("splay_rotate1: env_empty, insert two, rotate from node 2")

			--          2
			--         /
			--        1

			env_empty

			bst_int_int.insert (1, 1)
			bst_int_int.insert (2, 2)

			bst_int_int.rotate (bst_int_int.nodes[1])

			--          1
			--           \
			--            2

			Result :=
				bst_int_int.root.key = 1
		end

feature -- splay

	add_splay_splay_tests
		do
			add_boolean_case(agent splay_splay1)
		end

	splay_splay1: BOOLEAN
		do
			comment ("splay_splay1: splay, zig-zig")
			env_empty

			bst_int_int.insert (1, 1)
			bst_int_int.insert (2, 2)
			bst_int_int.insert (3, 3)

			bst_int_int.splay (bst_int_int.nodes[1])

			Result := bst_int_int.root = bst_int_int.nodes[1]
		end


feature -- search

	add_splay_search_tests
		do
			add_boolean_case (agent splay_search1)
		end

	splay_search1: BOOLEAN
		local
			l_search_result: STRING
		do
			comment ("splay_search1: env_root_insert_str_str, search 'g'")

			env_root_insert_str_str

			l_search_result := bst_str_str.search("g")

			Result := l_search_result ~ "g"

		end

feature -- insert

	add_splay_insert_tests
		do
			add_boolean_case (agent splay_insert1)
		end

	splay_insert1: BOOLEAN
		local
		do
			comment ("splay_insert1: env_empty, insert 1, check the root's key")

			env_empty

			bst_int_int.insert(1, 1)

			Result :=
				bst_int_int.root.key ~ 1
		end

feature -- delete

	add_splay_delete_tests
		do
			add_boolean_case (agent splay_delete1)
		end

	splay_delete1: BOOLEAN
		local
		do
			comment ("splay_delete1: env_empty, insert 1, delete 1, check its count")

			env_empty

			bst_int_int.insert (1, 1)
--			bst_int_int.insert (2, 2)

			bst_int_int.delete (1)

			Result :=
				bst_int_int.count = 0

		end

feature -- SPLAY_TREE

	add_t_has
		do
			add_boolean_case (agent t_has)
		end

	t_has: BOOLEAN
		local
			tree: SPLAY_TREE[INTEGER, STRING]
		do
			comment ("t_has: Testing has functionality")
			create tree.make

			Result := tree.root.is_external
			check Result end
			Result := tree.count = 0
			check Result end
			Result := tree.is_empty
			check Result end

			tree.root.make_internal (4, "4")
			Result := tree.has (4) = true
			check Result end
			Result := tree.count = 1
			check Result end
			Result := not tree.is_empty
			check Result end
			Result := tree.has (1) = false
			check Result end
		end

		add_t_has_node
			do
				add_boolean_case (agent t_has_node)
			end

		t_has_node: BOOLEAN
			local
				tree: SPLAY_TREE[INTEGER, STRING]
			do
				comment ("t_has_node: Testing has_node functionality")
				create tree.make

				Result := tree.root.is_external
				check Result end

				tree.root.make_internal (4, "4")
				Result := tree.has_node (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4")) = true
				check Result end
				Result := tree.has_node (create {TREE_NODE[INTEGER, STRING]}.make_internal (41, "1")) = false
				check Result end
			end

		add_t_relink
			do
				add_boolean_case (agent t_relink)
			end

		t_relink: BOOLEAN
		local
			tree: SPLAY_TREE[INTEGER, STRING]
			left_child: TREE_NODE[INTEGER, STRING]
			right_child: TREE_NODE[INTEGER, STRING]
		do
			comment ("t_relink: Testing child relink functionality")
			create tree.make

			Result := tree.root.is_external
			check Result end

			tree.root.make_internal (4, "4")
			Result := tree.has_node (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4")) = true
			check Result end
			Result := tree.has_node (create {TREE_NODE[INTEGER, STRING]}.make_internal (41, "1")) = false
			check Result end

			-- Creating the left child and relinking it
			create left_child.make_internal (2, "2")
			tree.relink (tree.root, left_child, true)
			Result := tree.root.left = left_child
			check Result end

			-- Creating the right child and relinking it
			create right_child.make_internal (6, "6")
			tree.relink (tree.root, right_child, false)
			Result := tree.root.right = right_child
			check Result end
		end

		add_t_rotate_case_1_1
			do
				add_boolean_case (agent t_rotate_case_1_1)
			end

		t_rotate_case_1_1: BOOLEAN
		local
			old_tree: SPLAY_TREE[INTEGER, STRING]
			new_tree: SPLAY_TREE[INTEGER, STRING]
			list_of_tre_nodes: LIST[TREE_NODE[INTEGER, STRING]]
		do
			comment ("t_rotate_case_1_1: Testing node rotation functionality, case 1.1")

--			-- Old tree
--					 8
--				  /     \
--				4        12
--			  /   \    /   \
--			2      6  10    14
--        /   \   / \ / \  /  \
--       1     3  5 7 9 11 13  15
			create old_tree.make
			Result := old_tree.root.is_external
			check Result end
			old_tree.root.make_internal (8, "8")
			-- Left side of the tree
			old_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4"))
			if attached old_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
				if attached left.right as left_right then
					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				end
				if attached left.left as left_left then
					left_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
					left_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
				end
			end
			-- Right side of the tree
			old_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (12, "12"))
			if attached old_tree.root.right as right then
				right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (14, "14"))
				if attached right.right as right_right then
					right_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (13, "13"))
					right_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (15, "15"))
				end
				if attached right.left as right_left then
					right_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (9, "9"))
					right_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (11, "11"))
				end
			end

			-- (case 1.1) - Parent is left child of grand parent (I am left child of parent)
--			-- Rotating node with key 2
			if attached old_tree.root.left as left then
				if attached left.left as left_left then
					old_tree.rotate (left_left)
				end
			end
--			-- New tree
--					 8
--				  /     \
--				2        12
--			  /   \    /   \
--			1      4  10    14
--                / \ / \  /  \
--                3 6 9 11 13  15
--					/\
--				   5  7
			create new_tree.make
			new_tree.root.make_internal (8, "8")
			-- Left side of the tree
			new_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			if attached new_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4"))
				if attached left.right as left_right then
					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
					if attached left_right.right as left_right_right then
						left_right_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
						left_right_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
					end
				end
			end
			-- Right side of the tree
			new_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (12, "12"))
			if attached new_tree.root.right as right then
				right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (14, "14"))
				if attached right.right as right_right then
					right_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (13, "13"))
					right_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (15, "15"))
				end
				if attached right.left as right_left then
					right_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (9, "9"))
					right_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (11, "11"))
				end
			end
			-- Check if old_tree is the same as new_tree after rotation
			Result := old_tree.root.is_same_tree (new_tree.root) = true
			check Result end
		end

		add_t_rotate_case_1_2
			do
				add_boolean_case (agent t_rotate_case_1_2)
			end

		t_rotate_case_1_2: BOOLEAN
		local
			old_tree: SPLAY_TREE[INTEGER, STRING]
			new_tree: SPLAY_TREE[INTEGER, STRING]
			list_of_tre_nodes: LIST[TREE_NODE[INTEGER, STRING]]
		do
			comment ("t_rotate_case_1_2: Testing node rotation functionality, case 1.2")

--			-- Old tree
--					 8
--				  /     \
--				4        12
--			  /   \    /   \
--			2      6  10    14
--        /   \   / \ / \  /  \
--       1     3  5 7 9 11 13  15
			create old_tree.make
			Result := old_tree.root.is_external
			check Result end
			old_tree.root.make_internal (8, "8")
			-- Left side of the tree
			old_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4"))
			if attached old_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
				if attached left.right as left_right then
					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				end
				if attached left.left as left_left then
					left_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
					left_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
				end
			end
			-- Right side of the tree
			old_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (12, "12"))
			if attached old_tree.root.right as right then
				right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (14, "14"))
				if attached right.right as right_right then
					right_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (13, "13"))
					right_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (15, "15"))
				end
				if attached right.left as right_left then
					right_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (9, "9"))
					right_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (11, "11"))
				end
			end

			-- (case 1.2) - Parent is left child of grand parent (I am right of parent)
--			-- Rotating node with key 6
			if attached old_tree.root.left as left then
				if attached left.right as left_right then
					old_tree.rotate (left_right)
				end
			end
--			-- New tree
--					 8
--				  /     \
--				6        12
--			  /   \    /   \
--			4      7  10    14
--        /   \       / \  /  \
--       2     5      9 11 13  15
--		/\
--	   1  3
			create new_tree.make
			new_tree.root.make_internal (8, "8")
			-- Left side of the tree
			new_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
			if attached new_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				if attached left.left as left_left then
					left_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
					left_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
					if attached left_left.left as left_left_left then
						left_left_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
						left_left_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
					end
				end
			end
			-- Right side of the tree
			new_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (12, "12"))
			if attached new_tree.root.right as right then
				right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (14, "14"))
				if attached right.right as right_right then
					right_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (13, "13"))
					right_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (15, "15"))
				end
				if attached right.left as right_left then
					right_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (9, "9"))
					right_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (11, "11"))
				end
			end
			-- Check if old_tree is the same as new_tree after rotation
			Result := old_tree.root.is_same_tree (new_tree.root) = true
			check Result end
		end

		add_t_rotate_case_2_1
			do
				add_boolean_case (agent t_rotate_case_2_1)
			end

		t_rotate_case_2_1: BOOLEAN
		local
			old_tree: SPLAY_TREE[INTEGER, STRING]
			new_tree: SPLAY_TREE[INTEGER, STRING]
			list_of_tre_nodes: LIST[TREE_NODE[INTEGER, STRING]]
		do
			comment ("t_rotate_case_2_1: Testing node rotation functionality, case 2.1")

--			-- Old tree
--					 8
--				  /     \
--				4        12
--			  /   \    /   \
--			2      6  10    14
--        /   \   / \ / \  /  \
--       1     3  5 7 9 11 13  15
			create old_tree.make
			Result := old_tree.root.is_external
			check Result end
			old_tree.root.make_internal (8, "8")
			-- Left side of the tree
			old_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4"))
			if attached old_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
				if attached left.right as left_right then
					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				end
				if attached left.left as left_left then
					left_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
					left_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
				end
			end
			-- Right side of the tree
			old_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (12, "12"))
			if attached old_tree.root.right as right then
				right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (14, "14"))
				if attached right.right as right_right then
					right_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (13, "13"))
					right_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (15, "15"))
				end
				if attached right.left as right_left then
					right_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (9, "9"))
					right_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (11, "11"))
				end
			end

			-- (case 2.1) - Parent is right child of grand parent (I am left of parent)
--			-- Rotating node with key 10
			if attached old_tree.root.right as right then
				if attached right.left as right_left then
					old_tree.rotate (right_left)
				end
			end
--			-- New tree
--					 8
--				  /     \
--				4        10
--			  /   \    /   \
--			2      6   9    12
--        /   \   / \      /  \
--       1     3  5 7      11  14
--						   	   /\
--	   						  13 15	
			create new_tree.make
			new_tree.root.make_internal (8, "8")
			-- Left side of the tree
			new_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4"))
			if attached new_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
				if attached left.right as left_right then
					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				end
				if attached left.left as left_left then
					left_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
					left_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
				end
			end
			-- Right side of the tree
			new_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
			if attached new_tree.root.right as right then
				right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (9, "9"))
				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (12, "12"))
				if attached right.right as right_right then
					right_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (11, "13"))
					right_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (14, "14"))
					if attached right_right.right as right_right_right then
						right_right_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (13, "13"))
						right_right_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (15, "15"))
					end
				end
			end
			-- Check if old_tree is the same as new_tree after rotation
			Result := old_tree.root.is_same_tree (new_tree.root) = true
			check Result end
		end

		add_t_rotate_case_2_2
			do
				add_boolean_case (agent t_rotate_case_2_2)
			end

		t_rotate_case_2_2: BOOLEAN
		local
			old_tree: SPLAY_TREE[INTEGER, STRING]
			new_tree: SPLAY_TREE[INTEGER, STRING]
			list_of_tre_nodes: LIST[TREE_NODE[INTEGER, STRING]]
		do
			comment ("t_rotate_case_2_2: Testing node rotation functionality, case 2.2")

--			-- Old tree
--					 8
--				  /     \
--				4        12
--			  /   \    /   \
--			2      6  10    14
--        /   \   / \ / \  /  \
--       1     3  5 7 9 11 13  15
			create old_tree.make
			Result := old_tree.root.is_external
			check Result end
			old_tree.root.make_internal (8, "8")
			-- Left side of the tree
			old_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4"))
			if attached old_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
				if attached left.right as left_right then
					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				end
				if attached left.left as left_left then
					left_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
					left_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
				end
			end
			-- Right side of the tree
			old_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (12, "12"))
			if attached old_tree.root.right as right then
				right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (14, "14"))
				if attached right.right as right_right then
					right_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (13, "13"))
					right_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (15, "15"))
				end
				if attached right.left as right_left then
					right_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (9, "9"))
					right_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (11, "11"))
				end
			end

			-- (case 2.2) - Parent is right child of grand parent (I am right of parent)
--			-- Rotating node with key 14
			if attached old_tree.root.right as right then
				if attached right.right as right_right then
					old_tree.rotate (right_right)
				end
			end
--			-- New tree
--					 8
--				  /     \
--				4        14
--			  /   \     /  \
--			2      6   12   15
--        /   \   / \  / \
--       1     3  5 7 10 13
--				      /\
--	   			     9 11	
			create new_tree.make
			new_tree.root.make_internal (8, "8")
			-- Left side of the tree
			new_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4"))
			if attached new_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
				if attached left.right as left_right then
					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				end
				if attached left.left as left_left then
					left_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
					left_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
				end
			end
			-- Right side of the tree
			new_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (14, "14"))
			if attached new_tree.root.right as right then
				right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (12, "12"))
				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (15, "15"))
				if attached right.left as right_left then
					right_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
					right_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (13, "13"))
					if attached right_left.left as right_left_left then
						right_left_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (9, "9"))
						right_left_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (11, "11"))
					end
				end
			end
			-- Check if old_tree is the same as new_tree after rotation
			Result := old_tree.root.is_same_tree (new_tree.root) = true
			check Result end
		end

		add_t_rotate_case_3
			do
				add_boolean_case (agent t_rotate_case_3)
			end

		t_rotate_case_3: BOOLEAN
		local
			old_tree: SPLAY_TREE[INTEGER, STRING]
			new_tree: SPLAY_TREE[INTEGER, STRING]
			list_of_tre_nodes: LIST[TREE_NODE[INTEGER, STRING]]
		do
			comment ("t_rotate_case_3: Testing node rotation functionality, case 3")
			-- Basic tree test
--					2
--				  /
--				1
			create old_tree.make
			Result := old_tree.root.is_external
			check Result end
			old_tree.root.make_internal (2, "2")
			-- Left side of the tree
			old_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))

--			-- Rotating node with key 1
			if attached old_tree.root.left as left then
					old_tree.rotate (left)
			end
--			-- New tree
--					 1
--				      \
--						2
			create new_tree.make
			new_tree.root.make_internal (1, "1")
			-- Left side of the tree
			new_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))

			-- Check if old_tree is the same as new_tree after rotation
			Result := old_tree.root.is_same_tree (new_tree.root) = true
			check Result end

----			-- Old tree
----					 8
----				  /     \
----				4        12
----			  /   \    /   \
----			2      6  10    14
----        /   \   / \ / \  /  \
----       1     3  5 7 9 11 13  15
--			create old_tree.make
--			Result := old_tree.root.is_external
--			check Result end
--			old_tree.root.make_internal (8, "8")
--			-- Left side of the tree
--			old_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4"))
--			if attached old_tree.root.left as left then
--				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
--				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
--				if attached left.right as left_right then
--					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
--					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
--				end
--				if attached left.left as left_left then
--					left_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
--					left_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
--				end
--			end
--			-- Right side of the tree
--			old_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (12, "12"))
--			if attached old_tree.root.right as right then
--				right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
--				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (14, "14"))
--				if attached right.right as right_right then
--					right_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (13, "13"))
--					right_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (15, "15"))
--				end
--				if attached right.left as right_left then
--					right_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (9, "9"))
--					right_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (11, "11"))
--				end
--			end

--			-- (case 3) - Grand parent not exist (I am left of parent, aka root)
----			-- Rotating node with key 4
--			if attached old_tree.root.left as left then
--					old_tree.rotate (left)
--			end
----			-- New tree
----					 4
----				  /     \
----				2        8
----			  /   \    /   \
----			1      3   6    12
----                    / \  /  \
----                    5 7 10  14
----				          /\  /  \
----	   			         9 11 13 15	
--			create new_tree.make
--			new_tree.root.make_internal (4, "4")
--			-- Left side of the tree
--			new_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
--			if attached new_tree.root.left as left then
--				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
--				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
--			end
--			-- Right side of the tree
--			new_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (8, "8"))
--			if attached new_tree.root.right as right then
--				right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
--				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (12, "12"))
--				if attached right.left as right_left then
--					right_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
--					right_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
--				end
--				if attached right.right as right_right then
--					right_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
--					if attached right_right.left as right_right_left then
--						right_right_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (9, "9"))
--						right_right_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (11, "11"))
--					end
--					right_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (14, "14"))
--					if attached right_right.right as right_right_right then
--						right_right_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (13, "13"))
--						right_right_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (15, "15"))
--					end
--				end
--			end
--			-- Check if old_tree is the same as new_tree after rotation
--			Result := old_tree.root.is_same_tree (new_tree.root) = true
--			check Result end
		end

		add_t_rotate_case_4
			do
				add_boolean_case (agent t_rotate_case_4)
			end

		t_rotate_case_4: BOOLEAN
		local
			old_tree: SPLAY_TREE[INTEGER, STRING]
			new_tree: SPLAY_TREE[INTEGER, STRING]
			list_of_tre_nodes: LIST[TREE_NODE[INTEGER, STRING]]
		do
			comment ("t_rotate_case_4: Testing node rotation functionality, case 4")
			-- Basic tree test
--					1
--				     \
--				      2
			create old_tree.make
			Result := old_tree.root.is_external
			check Result end
			old_tree.root.make_internal (1, "1")
			-- Left side of the tree
			old_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))

--			-- Rotating node with key 2
			if attached old_tree.root.right as right then
					old_tree.rotate (right)
			end
--			-- New tree
--					2
--				  /
--				1
			create new_tree.make
			new_tree.root.make_internal (2, "2")
			-- Left side of the tree
			new_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))

			-- Check if old_tree is the same as new_tree after rotation
			Result := old_tree.root.is_same_tree (new_tree.root) = true
			check Result end

--			-- Old tree
--					 8
--				  /     \
--				4        12
--			  /   \    /   \
--			2      6  10    14
--        /   \   / \ / \  /  \
--       1     3  5 7 9 11 13  15
			create old_tree.make
			Result := old_tree.root.is_external
			check Result end
			old_tree.root.make_internal (8, "8")
			-- Left side of the tree
			old_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4"))
			if attached old_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
				if attached left.right as left_right then
					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				end
				if attached left.left as left_left then
					left_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
					left_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
				end
			end
			-- Right side of the tree
			old_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (12, "12"))
			if attached old_tree.root.right as right then
				right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (14, "14"))
				if attached right.right as right_right then
					right_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (13, "13"))
					right_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (15, "15"))
				end
				if attached right.left as right_left then
					right_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (9, "9"))
					right_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (11, "11"))
				end
			end
			-- (case 4) - Grand parent not exist (I am right of parent, aka root)
--			-- Rotating node with key 12
			if attached old_tree.root.right as right then
					old_tree.rotate (right)
			end
--			-- New tree
--					 12
--				  /     \
--				8        14
--			  /   \    /   \
--			4      10  13    15
--        /   \   / \
--       2     6  9 11
--		 /\  /  \
--	   	1  3 5  7	
			create new_tree.make
			new_tree.root.make_internal (12, "12")
			-- Left side of the tree
			new_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (8, "8"))
			if attached new_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4"))
				if attached left.left as left_left then
					left_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
					left_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
					if attached left_left.left as left_left_left then
						left_left_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
						left_left_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
					end
					if attached left_left.right as left_left_right then
						left_left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
						left_left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
					end
				end
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
				if attached left.right as left_right then
					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (9, "9"))
					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (11, "11"))
				end
			end
			-- Right side of the tree
			new_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (14, "14"))
			if attached new_tree.root.right as right then
				right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (13, "13"))
				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (15, "15"))
			end
			-- Check if old_tree is the same as new_tree after rotation
			Result := old_tree.root.is_same_tree (new_tree.root) = true
			check Result end
		end

		add_t_rotate_case_5
			do
				add_violation_case_with_tag ("has_a_parent_to_rotate", agent t_rotate_case_5)
			end

		t_rotate_case_5
		local
			old_tree: SPLAY_TREE[INTEGER, STRING]
			new_tree: SPLAY_TREE[INTEGER, STRING]
			list_of_tre_nodes: LIST[TREE_NODE[INTEGER, STRING]]
		do
			comment ("t_rotate_case_5: Testing node rotation functionality, case 5")
			-- Basic tree test
--					1
--				     \
--				      2
			create old_tree.make
			old_tree.root.make_internal (1, "1")
			-- Left side of the tree
			old_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))

--			-- Rotating node with key 1
			old_tree.rotate (old_tree.root)

--			-- Old tree
--					 8
--				  /     \
--				4        12
--			  /   \    /   \
--			2      6  10    14
--        /   \   / \ / \  /  \
--       1     3  5 7 9 11 13  15
			create old_tree.make
			old_tree.root.make_internal (8, "8")
			-- Left side of the tree
			old_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (4, "4"))
			if attached old_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (6, "6"))
				if attached left.right as left_right then
					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				end
				if attached left.left as left_left then
					left_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
					left_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (3, "3"))
				end
			end
			-- Right side of the tree
			old_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (12, "12"))
			if attached old_tree.root.right as right then
				right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (14, "14"))
				if attached right.right as right_right then
					right_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (13, "13"))
					right_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (15, "15"))
				end
				if attached right.left as right_left then
					right_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (9, "9"))
					right_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (11, "11"))
				end
			end
			old_tree.rotate (old_tree.root)
		end

		add_t_splay_1
			do
				add_boolean_case (agent t_splay_1)
			end

		t_splay_1: BOOLEAN
		local
			old_tree: SPLAY_TREE[INTEGER, STRING]
			new_tree: SPLAY_TREE[INTEGER, STRING]
		do
			comment ("t_splay_1: Testing the splay functionality of a splay tree, case 1, zig-zig")

			-- Old tree
--					 10
--				  /     \
--				2        17
--			  /   \
--			1      7
--                / \
--                5  8
			create old_tree.make
			old_tree.root.make_internal (10, "10")
			-- Left side of the tree
			old_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			if attached old_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				if attached left.right as left_right then
					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (8, "8"))
				end
			end
			-- Right side of the tree
			old_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (17, "17"))

			-- Splaying from node with key 1
			if attached old_tree.root.left as left then
				if attached left.left as left_left then
					old_tree.splay (left_left)
				end
			end

			-- New tree
--					 1
--				       \
--			       	    2
--			             \
--			             10
--                     /   \
--                    7     17
--					/  \
--				   5    8
			create new_tree.make
			new_tree.root.make_internal (1, "1")
			-- Left side of the tree
			new_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			if attached new_tree.root.right as right then
				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
				if attached right.right as right_right then
					right_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
					right_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (17, "17"))
					if attached right_right.left as right_right_left then
						right_right_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
						right_right_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (8, "8"))
					end
				end
			end

			-- Check if old_tree is the same as new_tree after splaying
			Result := old_tree.root.is_same_tree (new_tree.root) = true
			check Result end

		end

		add_t_splay_2
			do
				add_boolean_case (agent t_splay_2)
			end

		t_splay_2: BOOLEAN
		local
			old_tree: SPLAY_TREE[INTEGER, STRING]
			new_tree: SPLAY_TREE[INTEGER, STRING]
		do
			comment ("t_splay_2: Testing the splay functionality of a splay tree, case 2, zig-zag")

			-- Old tree
--					 10
--				  /     \
--				2        17
--			  /   \
--			1      7
--                / \
--                5  8
			create old_tree.make
			old_tree.root.make_internal (10, "10")
			-- Left side of the tree
			old_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			if attached old_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				if attached left.right as left_right then
					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (8, "8"))
				end
			end
			-- Right side of the tree
			old_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (17, "17"))

			-- Splaying from node with key 7
			if attached old_tree.root.left as left then
				if attached left.right as left_rght then
					old_tree.splay (left_rght)
				end
			end

			-- New tree
--					 7
--				  /     \
--				2        10
--			  /   \     /   \
--			1      5   8     17
			create new_tree.make
			new_tree.root.make_internal (7, "7")
			-- Left side of the tree
			new_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			if attached new_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
			end
			-- Right side of the tree
			new_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
			if attached new_tree.root.right as right then
				right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (8, "8"))
				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (17, "17"))
			end

			-- Check if old_tree is the same as new_tree after splaying
			Result := old_tree.root.is_same_tree (new_tree.root) = true
			check Result end
		end

		add_t_splay_3
			do
				add_boolean_case (agent t_splay_3)
			end

		t_splay_3: BOOLEAN
		local
			old_tree: SPLAY_TREE[INTEGER, STRING]
			new_tree: SPLAY_TREE[INTEGER, STRING]
		do
			comment ("t_splay_3: Testing the splay functionality of a splay tree, case 3, zig")

			-- Old tree
--					 10
--				  /     \
--				2        17
--			  /   \
--			1      7
--                / \
--                5  8
			create old_tree.make
			old_tree.root.make_internal (10, "10")
			-- Left side of the tree
			old_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			if attached old_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				if attached left.right as left_right then
					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (8, "8"))
				end
			end
			-- Right side of the tree
			old_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (17, "17"))

			-- Splaying from node with key 2
			if attached old_tree.root.left as left then
					old_tree.splay (left)
			end

			-- New tree
--					 2
--				  /     \
--				1        10
--			           /   \
--			          7     17
--                   / \
--                   5  8
			create new_tree.make
			new_tree.root.make_internal (2, "2")
			-- Left side of the tree
			new_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
			-- Right side of the tree
			new_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (10, "10"))
			if attached new_tree.root.right as right then
				right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				if attached right.left as right_left then
					right_left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
					right_left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (8, "8"))
				end
				right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (17, "17"))
			end

			-- Check if old_tree is the same as new_tree after splaying
			Result := old_tree.root.is_same_tree (new_tree.root) = true
			check Result end
		end

		add_t_splay_4
			do
				add_boolean_case (agent t_splay_4)
			end

		t_splay_4: BOOLEAN
		local
			old_tree: SPLAY_TREE[INTEGER, STRING]
			new_tree: SPLAY_TREE[INTEGER, STRING]
		do
			comment ("t_splay_4: Testing the splay functionality of a splay tree, case 4, root")

			-- Old tree
--					 10
--				  /     \
--				2        17
--			  /   \
--			1      7
--                / \
--                5  8
			create old_tree.make
			old_tree.root.make_internal (10, "10")
			-- Left side of the tree
			old_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			if attached old_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				if attached left.right as left_right then
					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (8, "8"))
				end
			end
			-- Right side of the tree
			old_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (17, "17"))

			-- Splaying from node with key 10
					old_tree.splay (old_tree.root)

			-- New tree
--					 10
--				  /     \
--				2        17
--			  /   \
--			1      7
--                / \
--                5  8
			create new_tree.make
			new_tree.root.make_internal (10, "10")
			-- Left side of the tree
			new_tree.root.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (2, "2"))
			if attached new_tree.root.left as left then
				left.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (1, "1"))
				left.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (7, "7"))
				if attached left.right as left_right then
					left_right.insert_left (create {TREE_NODE[INTEGER, STRING]}.make_internal (5, "5"))
					left_right.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (8, "8"))
				end
			end
			-- Right side of the tree
			new_tree.root.insert_right (create {TREE_NODE[INTEGER, STRING]}.make_internal (17, "17"))

			-- Check if old_tree is the same as new_tree after splaying
			Result := old_tree.root.is_same_tree (new_tree.root) = true
			check Result end
		end

end

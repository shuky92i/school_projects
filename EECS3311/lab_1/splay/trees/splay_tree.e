note
	description: "[
		A self balancing binary search tree using a rotation called splaying.

		A splay tree lets most frequently(recently) accessed elements stay near
		the root. This allows comparably faster lookup to a recently accessed
		elements than a normal binary search tree.

		A splay tree does not have logarithmic upper bound respect to the height
		of the tree, however the splay tree has a guaranteed amortised logarithmic
		running time for insertions, searches, and deletion.
		]"
	author: "Jinho Hwang"
	date: "$Date$"
	revision: "$Revision$"

class
	SPLAY_TREE [K -> COMPARABLE, V -> ANY]

inherit
	BALANCED_BST [K, V]
		redefine
			out
		end

create 	-- Contrast this `create` clause with it being absent in `BALANCED_BST`.
		-- Because the `SPLAY_TREE` class is effective (not deferred), we must delcare
		-- a `create` clause that lists all commands that can be used as constructors.
	make

feature {NONE} -- Command

	make
			-- Makes the current balanced splay tree empty.
		do
			-- This implementation is given to you. Do not modify.
			create root.make_external
		ensure
			-- These postconditions are completed for you. Do not modify.
			root_exists:
				attached root
			root_empty:
				attached root as a_root and then
				a_root.count = 0
		end

feature -- Attribute

	root: TREE_NODE[K, V]
			-- The root of the splay tree.
			-- This root is never Void (i.e., it is always attached).

feature -- Traversal

	nodes: LIST[like root]  -- `like root`: each member in the list has its type
							-- corresponding to that of `root` (anchor type)
			-- Returns a linear order corresponding to an in-order traversal from the `root`.
		do
			-- This implementation is given to you. Do not modify.
			-- Caveat: The correctness of `{SPLAY_TREE}.nodes` depends solely on `{TREE_NODE}.nodes` that you implement.
			Result := root.nodes
		end

feature -- Basic

	has (p_key: K): BOOLEAN
			-- Does the current tree have a node storing key equal to `p_key`?
		do
			-- TODO: Implement this query so that the postcondition is satisfied.
			-- Hint: A splay tree has its root of type `TREE_NODE`.
			Result := root.has (p_key)

		ensure then -- In a descendant class, a `then` is needed after `ensure`. This is called sub-contracting, and we will learn about this later.
			root_has_the_node_with_the_p_key:
				-- TODO: Complete this postcondition.
				-- Hint: Return value is logically equivalent to whether or not `p_key` exists in the current tree.
				(Result = true implies root.has (p_key))
				and
				(root.has (p_key) implies Result = true)
		end

	has_node (p_node: TREE_NODE[K,V]): BOOLEAN
			-- Does current tree have a node same key as `p_node`?
		do
			-- TODO: Implement this query so that the postcondition is satisfied.
			-- Hint: A splay tree has its root of type `TREE_NODE`.
			Result := root.has_node (p_node)

		ensure then -- In a descendant class, a `then` is needed after `ensure`. This is called sub-contracting, and we will learn about this later.
			root_has_the_p_node:
				-- TODO: Complete this postcondition.
				-- Hint: Return value is logically equivalent to whether or not `p_node` exists in the current tree.
				(Result = true implies root.has_node (p_node))
				and
				(root.has_node (p_node) implies Result = true)
		end

	count: INTEGER
			-- Returns the number of nodes in the tree.
		do
			-- TODO: Implement this query so that the postcondition is satisfied.
			-- Hint: A splay tree has its root of type `TREE_NODE`.
			Result := root.count

		ensure then -- In a descendant class, a `then` is needed after `ensure`. This is called sub-contracting, and we will learn about this later.
			root_count:
				-- TODO: Complete this postcondition.
				-- Hint: Return value is the same as the size of subtree rooted as `root`.
				Result = root.count
		end

	is_empty: BOOLEAN
			-- Checks if the BST has no nodes.
		do
			-- TODO: Implement this query so that the postcondition is satisfied.
			-- Hint: When is this tree empty?
			Result := count = 0

		ensure then -- In a descendant class, a `then` is needed after `ensure`. This is called sub-contracting, and we will learn about this later.
			empty_if_count_is_zero:
				-- TODO: Complete this postcondition.
				-- Hint: Return value is logically equivalent to whether or not the subtree rooted at `root` is empty.
				Result = (root.count = 0)
		end

	relink (p_parent, p_child: TREE_NODE[K, V]; p_make_left_child: BOOLEAN)
			-- If `p_make_left_child` is true, replace `p_child` as the left child of `p_parent`.
			-- Otherwise, replace `p_child` as the right child of `p_parent`.
		do
			-- TODO: Complete the implementation so that the postcondition is satisfied.
			if p_make_left_child then
				p_parent.left := p_child
			else
				p_parent.right := p_child
			end
			p_child.parent := p_parent

		ensure
			childs_parent_is_linked:
				-- TODO: Complete this postcondition.
				-- Hint: `p_child`'s parent must be consistent.
				p_child.parent = p_parent

			case_of_relinking_the_left_child:
				-- TODO: Complete this postcondition.
				p_make_left_child implies p_parent.left = p_child

			case_of_relinking_the_right_child:
				-- TODO: Complete this postcondition.
				not p_make_left_child implies p_parent.right = p_child
		end

feature -- Intermediate

	-- For simplicity of this lab, we do not consider postconditions for this section of intermediate splay operations.
	-- As an optional challenge, what postconditions can you come up with?
	-- Discuss your answer with Jinho (TA) or Jackie (instructor).
	-- Do not include your answer in the submission for grading.

	rotate (p_node: TREE_NODE[K, V])
			-- Performs a single rotation from the node `p_node`.
		require
			-- These preconditions are given to you. Do not modify them.
			has_a_parent_to_rotate:
				attached p_node.parent
		local
			p_node_left_subtree_node: TREE_NODE[K, V]
			p_node_right_subtree_node: TREE_NODE[K, V]
		do
			-- TODO: Complete the implementation.
			-- Hint: Refer to the `Problem` and `Tutorials` sections of your lab instructions for details.

			-- Store pointers to both subrees of p_node
			p_node_left_subtree_node := p_node.left
			p_node_right_subtree_node := p_node.right

			if attached p_node.parent as node_parent then
				-- Both parent and grandparent exist
				if attached node_parent.parent as node_grandparnt then
					-- Case 1: I am left child of my parent, rotate right
					if node_parent.left = p_node then
						-- case 1.1: Parent is left child of grand parent
						if node_grandparnt.left = node_parent then
							relink (node_grandparnt, p_node, true) -- Replace np with n (as ts left child)
							relink (p_node, node_parent, false) -- Set n's right child as np
							-- Set np's left child as n's previous right child
							if attached p_node_right_subtree_node then
								relink (node_parent, p_node_right_subtree_node, true)
							end


						-- case 1.2: Parent is right child of grand parent
						else
							relink (node_grandparnt, p_node, false) -- Replace np with n (as its right child)
							relink (p_node, node_parent, false) -- Set n's right child as np
							-- Set np's left child as n's previous right child
							if attached p_node_right_subtree_node then
								relink (node_parent, p_node_right_subtree_node, true)
							end
						end

					-- Case 2: I am right child of my parent, rotate left
					else
						-- case 2.1: Parent is left child of grand parent
						if node_grandparnt.left = node_parent then
							relink (node_grandparnt, p_node, true) -- Replace np with n (as ts left child)
							relink (p_node, node_parent, true) -- Set n's left child as np
							-- Set np's right child as n's previous left child
							if attached p_node_left_subtree_node then
								relink (node_parent, p_node_left_subtree_node, false)
							end

						-- case 2.2: Parent is right child of grand parent
						else
							relink (node_grandparnt, p_node, false) -- Replace np with n (as ts right child)
							relink (p_node, node_parent, true) -- Set n's left child as np
							-- Set np's right child as n's previous left child
							if attached p_node_left_subtree_node then
								relink (node_parent, p_node_left_subtree_node, false)
							end
						end

					end

				-- Parent exists, grandparent does not, meaning I will become the root one the rotation is done
				-- Cache old state data of root
				elseif not attached node_parent.parent then
					-- Case 3: I am left child of my parent (the root), rotate right
					if node_parent.left = p_node then
						relink (p_node, create {TREE_NODE[K, V]}.make_external, false) -- Cut off p_node's right child
						p_node.parent := Void
						if attached p_node_right_subtree_node then
							relink (root, p_node_right_subtree_node, true) -- Cut off root's left child and set it as p_node_right_subtree_node
						end
						relink (p_node, root, false) -- Set root as p_node's right child
						root := p_node -- Update root


					-- Case 4: I am right child of my parent (the root), rotate left
					else
						relink (p_node, create {TREE_NODE[K, V]}.make_external, true) -- Cut off p_node's left child
						p_node.parent := Void
						if attached p_node_left_subtree_node then
							relink (root, p_node_left_subtree_node, false) -- Cut off root's right child and set it as p_node_left_subtree_node
						end
						relink (p_node, root, true) -- Set root as p_node's left child
						root := p_node -- Update root
					end
				end

			-- Case 5: Parent does not exist, meaning I am root, do nothing
			elseif not attached p_node.parent then
				-- Do nothing
				-- We will not get here in the first place because the precondition does not allow it
			end

		end

	splay(p_node: TREE_NODE[K,V])
			-- Iteratively, splay the node `p_node` up to the root.
			-- Each iteration may trigger one or two rotations.
		local
			current_node: TREE_NODE[K,V]
		do
			-- TODO: Complete the implementation.
			-- Hint: Refer to the `Problem` and `Tutorials` sections of your lab instructions for details.
			from
				current_node := p_node
			until
				not attached current_node.parent -- Until p_node becomes root
			loop
				if attached current_node.parent as current_node_parent then
					-- Both parent and grandparent exist
					if attached current_node_parent.parent as current_node_grandparent then
						-- case 1: zig-zig
						-- left zig-zig or right zig-zig
						if
							(current_node = current_node_parent.left) and (current_node_parent = current_node_grandparent.left)
							or
							(current_node = current_node_parent.right) and (current_node_parent = current_node_grandparent.right)
							then
								rotate (current_node_parent)
								rotate (current_node)
						-- Case 2: zig-zag
						-- left-right or right-left	
						elseif
							(current_node = current_node_parent.left) and (current_node_parent = current_node_grandparent.right)
							or
							(current_node = current_node_parent.right) and (current_node_parent = current_node_grandparent.left)
							then
								rotate (current_node)
								rotate (current_node)
						end


					-- Parent exists, grandparent does not
					elseif not attached current_node_parent.parent then
						-- Case 3: zig
						rotate (current_node)
					end

				-- Case 4: Parent does not exist, meaning I am root, do nothing
				elseif not attached p_node.parent then
					-- Do nothing
					-- We will not get here in the first place because the loop won't reach here. This is just for my better understanding
				end
			end

		end

feature -- Advanced

	search (p_key: K): detachable V
			-- Returns the value mapped from the search key `p_key`.
		local
			node_found: TREE_NODE[K,V]
		do
			-- TODO: Implement this command so that the postcondition is satisfied.
			-- Hint 1: You might want to reuse how search is done in `TREE_NODE`.
			-- Hint 2: The current tree after a successful search should be restructured
			-- 		so that more frequently accessed nodes are brought closer to the root.
			-- Hint 3: Refer to the `Problem` and `Tutorials` sections of your lab instructions for details.
			node_found := root.tree_search (p_key)
			if node_found.is_internal then
				splay (node_found)
				Result := root.value
			else
				if attached node_found.parent as node_found_parent then
					splay (node_found_parent)
				end
			end


		ensure then -- In a descendant class, a `then` is needed after `ensure`. This is called sub-contracting, and we will learn about this later.
			-- This postcondition is completed for you. Do not modify.
			count_is_same:
				count = (old Current.deep_twin).count

			case_of_key_found:
				-- TODO: Complete this postcondition.
				-- Hint: If `p_key` exists within the subtree rooted at `Current`,
				-- 		the result must be the value of the node we searched.
				(old Current.deep_twin).has(p_key) implies (Result ~ (old Current.deep_twin).root.value_search(p_key))

			case_of_key_not_found:
				-- TODO: Complete this postcondition.
				-- Hint: If `p_key` does not exist within the subtree rootd at `Current`,
				-- 		the result must be the value of the node that does not explicitly hold a value.
				not (old Current.deep_twin).has(p_key) implies not attached Result

			consistent_in_orders:
				-- TODO: Complete this postcondition.
				-- Hint 1. Performing in-order traversals before and after the search operation
				-- 		   yield two identical sequences of nodes.
				-- Hint 2. If you want to compare contents two lists, say `list1` ~ `list2`,
				--		   you must make sure that `list1.object_comparison` and `list2.object_comparison` are both true.
				--		   e.g., writing `list1.compare_objects` changes `list1.object_comparison` to true.
				-- 		   Otherwise, `list1` ~ `list2` will only compare references of their stored items.
				-- Hint 3. Rather than comparing two lists directly using ~, you may write a
				--		   logical quantification (universal or existential) to compare them.
				across (old Current.deep_twin).nodes is old_tree_node all
					across nodes is new_tree_node some
						old_tree_node ~ new_tree_node
					end
				end
		end

	insert (p_key: K; p_value: V)
			-- Inserts a new node with the key `p_key` and the value `p_value`.
			-- It is required that `p_key` is not an existing key.
			-- It is expected that after the key-value pair is inserted into the tree,
			-- splay operation(s) are performed from the new node up to the root.
		require else -- In a descendant class, an `else` is needed after `require`. This is called sub-contracting, and we will learn about this later.
			-- This precondition is given to you. Do not modify it.
			no_previously_existing_key:
				not has(p_key)
		local
			external_target_node: TREE_NODE[K,V]
		do
			-- TODO: Implement this command so that the postcondition is satisfied.
			-- Hint: Refer to the `Problem` and `Tutorials` sections of your lab instructions for details.
			external_target_node := root.tree_search (p_key)
			external_target_node.set_to_internal (p_key, p_value)
			splay (external_target_node)

		ensure then -- In a descendant class, a `then` is needed after `ensure`. This is called sub-contracting, and we will learn about this later.
			size_incremented:
				-- TODO: Complete this postcondition.
				count = (old Current.deep_twin).count + 1

			has_inserted_node:
				-- TODO: Complete this postcondition.
				has_node (create {TREE_NODE[K, V]}.make_internal (p_key, p_value))

			other_nodes_unchanged:
				-- TODO: Complete this postcondition.
				-- Hint 1: Consider comparing the old list of `nodes` (from an in-order traversal) with the new list of `nodes`.
				-- Hint 2: Every node except the one that was inserted should be same.

			-- The old tree will not have the inserted key
			-- For all nodes in old_tree, there exists a node in new_tree such that: old_tree_node ~ new_tree_node
			across (old Current.deep_twin).nodes is old_tree_node all
				across nodes is new_tree_node some
					old_tree_node ~ new_tree_node
				end
			end
		end

	delete (p_key: K)
		-- Deletes an existing node with the key equal to `p_key`.
		-- Supplier requires that:
		-- 		A node with the key `p_key` exists.
		-- 		This node is an internal node.
		-- See the precondition of `{BALANCED_BST}.delete`.
		local
			searched_node: TREE_NODE[K, V]
		do
			-- TODO: Implement this command so that the postcondition is satisfied.
			-- Hint: Refer to the `Problem` and `Tutorials` sections of your lab instructions for details.
			searched_node := root.tree_search (p_key)
			splay (searched_node)

			-- At this point searched_node is the root
			-- Both children are not void (may be internal or external)
			if (attached root.left as root_left_subtree_node) and (attached root.right as root_right_subtree_node) then

				-- Case 1: Root has external children, make root external too
				if root_left_subtree_node.is_external and root_right_subtree_node.is_external then
					-- Replace root with an external node
					root_left_subtree_node.parent := Void
					root := root_left_subtree_node

				-- Case 2.1: Left child of root is internal, right is external
				elseif root_left_subtree_node.is_internal and root_right_subtree_node.is_external then
					-- Replace root with its left child
					root_left_subtree_node.parent := Void
					root := root_left_subtree_node

				-- Calse 2.2: Left child of root is external, right is internal
				elseif root_left_subtree_node.is_external and root_right_subtree_node.is_internal then
					-- Replace root with its right child
					root_right_subtree_node.parent := Void
					root := root_right_subtree_node

				-- Both children internal
				elseif root_left_subtree_node.is_internal and root_right_subtree_node.is_internal then
					-- Replace root with its left child
					root_left_subtree_node.parent := Void
					root := root_left_subtree_node
					-- Then add original root right subtree to the max of the new subtree (bottom right)
					relink (root.max_node, root_right_subtree_node, false)
				end
			end


		ensure then -- In a descendant class, a `then` is needed after `ensure`. This is called sub-contracting, and we will learn about this later.
			size_decremented:
				-- TODO: Complete this postcondition.
				count = (old Current.deep_twin).count - 1

			has_removed_node:
				-- TODO: Complete this postcondition.
				not has_node ((old Current.deep_twin).root.tree_search(p_key))

			other_nodes_unchanged:
				-- TODO: Complete this postcondition.
				-- Hint: Consider comparing the old list of `nodes` (from an in-order traversal) with the new list of `nodes`.
				--		 Every node except the one that was deleted should be same.

				-- If before deleting there was only 1 node, then logically all other nodes are unchanged as they don't exist
				-- Logical statement: For all nodes in old_tree, there exists a node in new_tree
				-- such that: (old_tree_node /= deleted_node) -> (old_tree_node = new_tree_node)
				(old Current.deep_twin).count > 1
				implies
				(
					across (old Current.deep_twin).nodes is old_tree_node all
						across nodes is new_tree_node some
							(old_tree_node /~ (old Current.deep_twin).root.tree_search(p_key))
							implies
							(old_tree_node ~ new_tree_node)
						end
					end
				)
		end

feature -- Out

	debug_output: STRING
			-- Debugger will show the `Result`.
			-- Do not modify this.
			-- [x<--(1, 1)-->(2, 2), x<--(2, 2)-->x]
		do
			Result := out
		end

	out: STRING
			-- Do not modify this.
			-- [x<--(1, 1)-->(2, 2), x<--(2, 2)-->x]
		do
			Result := "["

			across
				nodes is i_node
			loop
				if
					attached i_node.left as a_left and then
					attached i_node.right as a_right
				then
					Result := Result
						+ a_left.out
						+ "<--"
						+ i_node.out
						+ "-->"
						+ a_right.out
				else
					Result := Result
				end

				if
					i_node /= nodes.last
				then
					Result := Result + ", "
				end
			end

			Result := Result + "]"

		end

invariant
	-- These class invariants are given to you. Do not modify them.
	-- However, you may study them carefully because they
	-- specify the defintions of external vs. internal nodes.

	no_root_means_count_is_zero:
		(root.is_external) = (root.count = 0)

	root_does_not_have_a_parent:
		not attached root.parent

	count_one_or_more_means_root_exists:
		(root.count >= 1) = (root.is_internal)

	nodes_are_sorted:
		across
			1 |..| (root.count - 1) is i
		all
			root.nodes[i] < root.nodes[i + 1]
		end

	left_child_keeps_reference_to_parent:
		(
			across
				nodes is i_node
			all
				attached i_node.left as a_left implies
				a_left.parent = i_node
			end
		)

	right_child_keeps_reference_to_parent:
		(
			across
				nodes is i_node
			all
				attached i_node.right as a_right implies
				a_right.parent = i_node
			end
		)

	left_is_smaller:
		across
			nodes is i_node
		all
			(
				attached i_node.left as a_left and then
				a_left.is_internal
			)
			implies
			a_left < i_node
		end

	right_is_bigger:
		across
			nodes is i_node
		all
			(
				attached i_node.right as a_right and then
				a_right.is_internal
			)
			implies
			i_node < a_right
		end

end

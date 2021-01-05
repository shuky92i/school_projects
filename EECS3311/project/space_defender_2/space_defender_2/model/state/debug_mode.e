note
	description: "Summary description for {DEBUG_MODE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	DEBUG_MODE

inherit
	ANY
		redefine
			out
		end

create
	make_default

feature -- initialization

	make_default
		do
			-- Set initial strings
			enemy := "  Enemy:"
			projectile := "  Projectile:"
			natural_enemy_spawn := "  Natural Enemy Spawn:"

			friendly_projectile_action := "  Friendly Projectile Action:"
			friendly_projectile_action_delayed := ""

			enemy_projectile_action := "  Enemy Projectile Action:"
			enemy_projectile_action_delayed := ""

			starfighter_action := "  Starfighter Action:"
			starfighter_action_delayed := ""

			enemy_action := "  Enemy Action:"
			enemy_action_delayed := ""

			-- set constants
			enemy_code := 0
			projetile_code := 1
			natural_enemy_spawn_code := 2

			friendly_projectile_action_code := 3
			friendly_projectile_action_code_delayed := 4

			enemy_projectile_action_code := 5
			enemy_projectile_action_code_delayed := 6

			starfighter_action_code := 7
			starfighter_action_code_delayed := 8

			enemy_action_code := 9
			enemy_action_code_delayed := 10
		end

feature -- attributes

	-- strings
	enemy : STRING
	projectile: STRING
	natural_enemy_spawn: STRING

	friendly_projectile_action: STRING
	friendly_projectile_action_delayed: STRING assign set_friendly_projectile_action_delayed

	enemy_projectile_action: STRING
	enemy_projectile_action_delayed: STRING assign set_enemy_projectile_action_delayed

	starfighter_action: STRING
	starfighter_action_delayed: STRING assign set_starfighter_action_delayed

	enemy_action: STRING
	enemy_action_delayed: STRING assign set_enemy_action_delayed

	-- constants
	enemy_code: INTEGER
	projetile_code: INTEGER
	natural_enemy_spawn_code: INTEGER

	friendly_projectile_action_code: INTEGER
	friendly_projectile_action_code_delayed: INTEGER

	enemy_projectile_action_code: INTEGER
	enemy_projectile_action_code_delayed: INTEGER

	starfighter_action_code: INTEGER
	starfighter_action_code_delayed: INTEGER

	enemy_action_code: INTEGER
	enemy_action_code_delayed: INTEGER

feature -- setters
	set_enemy_projectile_action_delayed (p_debug_string: STRING)
		do
			enemy_projectile_action_delayed := p_debug_string
		end

	set_enemy_action_delayed (p_debug_string: STRING)
		do
			enemy_action_delayed := p_debug_string
		end

	set_starfighter_action_delayed (p_debug_string: STRING)
		do
			starfighter_action_delayed := p_debug_string
		end

	set_friendly_projectile_action_delayed (p_debug_string: STRING)
		do
			friendly_projectile_action_delayed := p_debug_string
		end

feature -- mutators

	insert_entry (container_code: INTEGER ; entry: STRING)
		require
			0 <= container_code and container_code <= 10
		do
			if container_code = enemy_code then
				enemy.append ("%N")
				enemy.append (entry)
			elseif container_code = projetile_code then
				projectile.append ("%N")
				projectile.append (entry)
			elseif container_code = natural_enemy_spawn_code then
				natural_enemy_spawn.append ("%N")
				natural_enemy_spawn.append (entry)

			-- friendly projectile handlers
			elseif container_code = friendly_projectile_action_code then
				friendly_projectile_action.append ("%N")
				friendly_projectile_action.append (entry)
			elseif container_code = friendly_projectile_action_code_delayed then
				if friendly_projectile_action_delayed.count > 0 then
					friendly_projectile_action_delayed.append ("%N")
				end
				friendly_projectile_action_delayed.append (entry)

			-- enemy projectile handlers
			elseif container_code = enemy_projectile_action_code then
				enemy_projectile_action.append ("%N")
				enemy_projectile_action.append (entry)
			elseif container_code = enemy_projectile_action_code_delayed then
				if enemy_projectile_action_delayed.count > 0 then
					enemy_projectile_action_delayed.append ("%N")
				end
				enemy_projectile_action_delayed.append (entry)

			-- starfighter handlers
			elseif container_code = starfighter_action_code then
				starfighter_action.append ("%N")
				starfighter_action.append (entry)
			elseif container_code = starfighter_action_code_delayed then
				if starfighter_action_delayed.count > 0 then
					starfighter_action_delayed.append ("%N")
				end
				starfighter_action_delayed.append (entry)

			-- enemy action handler
			elseif container_code = enemy_action_code then
				enemy_action.append ("%N")
				enemy_action.append (entry)
			elseif container_code = enemy_action_code_delayed then
				if enemy_action_delayed.count > 0 then
					enemy_action_delayed.append ("%N")
				end
				enemy_action_delayed.append (entry)

			end
		end

feature -- Queries

	out : STRING
		do
			create Result.make_empty
			Result.append (enemy)
			Result.append ("%N")
			Result.append (projectile)
			Result.append ("%N")
			Result.append (friendly_projectile_action)
			Result.append ("%N")
			Result.append (enemy_projectile_action)
			Result.append ("%N")
			Result.append (starfighter_action)
			Result.append ("%N")
			Result.append (enemy_action)
			Result.append ("%N")
			Result.append (natural_enemy_spawn)
		end

end

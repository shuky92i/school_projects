note
	description: ""
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	ETF_FIRE
inherit
	ETF_FIRE_INTERFACE
create
	make
feature -- command
	fire
    	do
			model.fire
			etf_cmd_container.on_change.notify ([Current])
    	end

end

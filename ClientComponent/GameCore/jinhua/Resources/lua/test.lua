-- for CCLuaEngine traceback

cc.FileUtils:getInstance():setPopupNotify(false)
cc.FileUtils:getInstance():addSearchPath("cocos2d/cocos/scripting/lua-bindings/script")
cc.FileUtils:getInstance():addSearchPath("lua/")
require "config"
local socket = require("socket.core")
--local http = require("socket.http")
require "cocos.init"
require("json")

function __G__TRACKBACK__(msg)
    print("----------------------------------------")
    print("LUA ERROR: " .. tostring(msg) .. "\n")
    print(debug.traceback())
    print("----------------------------------------")
end
 
 
local function main()
    -- avoid memory leak

    local cclog = function(...)
        print(string.format(...))
    end
	
    local function createLayerMap()
        local layerWroldMap = cc.Layer:create()
		local WinSize = cc.Director:getInstance():getVisibleSize()
		local LoginBtn=ccui.Button:create()
		LoginBtn:setTitleText("WxLogin")
		LoginBtn:setPosition(cc.p(WinSize.width/2,WinSize.height/2))
		
		local function Login(ref,msgtype)
			
		end
		LoginBtn:addTouchEventListener(Login)
		layerWroldMap:addChild(LoginBtn)
       
        return layerWroldMap

    end

	luaWxLogin()
    local scene = display.newScene("test")
    scene:addChild(createLayerMap())
    display.runScene(scene, nil, nil, nil)
	 
--	local host="192.168.1.18"
--	local port=8080
--	local c=socket.connect(host,port)
--	c:send("hello server")
 
	--c:send("i'm cocos client")
 --  local xhr = cc.XMLHttpRequest:new()
--	xhr.responseType = cc.XMLHTTPREQUEST_RESPONSE_ARRAY_BUFFER 
--	xhr:open("GET", "192.168.1.18:8080")
--	xhr:setRequestHeader("Content-Type", "application/json")
--	local function onReadyStateChange()  
--	local ll   = xhr.response -- 获得返回数据  
--	print("response:"..ll)
 --   end  
--	xhr:registerScriptHandler(onReadyStateChange)
  --  xhr:send()
--xhr:send(json.encode(par))
   -- cc.Director:getInstance():getRunningScene():addChild(createLayerMap(),3,1)
   
end

xpcall(main, __G__TRACKBACK__)
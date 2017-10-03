-- for CCLuaEngine traceback

cc.FileUtils:getInstance():setPopupNotify(false)
cc.FileUtils:getInstance():addSearchPath("cocos2d/cocos/scripting/lua-bindings/script")

require "config"
require "cocos.init"
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

        local bg = cc.Sprite:create("beng.png")
           
        bg:setPosition(cc.p(80,80))

        layerWroldMap:addChild(bg,1)

        return layerWroldMap

    end

    local scene = display.newScene("test")
    scene:addChild(createLayerMap())
    display.runScene(scene, nil, nil, nil)
   -- cc.Director:getInstance():getRunningScene():addChild(createLayerMap(),3,1)
   
end

xpcall(main, __G__TRACKBACK__)
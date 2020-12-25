#include<iostream>
#include<string>
#include<lua54/lua.hpp>

int main(){
    std::string cmd = "nice = 34 + 35";
    lua_State *L = luaL_newstate();
    int r = luaL_dostring(L, cmd.c_str());
    if(r == LUA_OK){
        lua_getglobal(L, "nice");
        if(lua_isnumber(L, -1)){
            float nice = static_cast<float>(lua_tonumber(L, -1));
            std::cout << "nice = " << nice << std::endl;
        }
    }else{
        std::string error_message = lua_tostring(L, -1);
        std::cout << error_message << std::endl;
    }
    r = luaL_dofile(L, "src/main.lua");
    if(r == LUA_OK){
        lua_getglobal(L, "nice");
        if(lua_isnumber(L, -1)){
            float nice = static_cast<float>(lua_tonumber(L, -1));
            std::cout << "nice = " << nice << std::endl;
        }
    }else{
        std::string error_message = lua_tostring(L, -1);
        std::cout << error_message << std::endl;
    }
    cmd = "nice = 3 ++ 12 3==";
    r = luaL_dostring(L, cmd.c_str());
    if(r == LUA_OK){
        lua_getglobal(L, "nice");
        if(lua_isnumber(L, -1)){
            float nice = static_cast<float>(lua_tonumber(L, -1));
            std::cout << "nice = " << nice << std::endl;
        }
    }else{
        std::string error_message = lua_tostring(L, -1);
        std::cout << error_message << std::endl;
    }
    lua_close(L);
    return 0;
}

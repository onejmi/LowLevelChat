package io.github.scarger.chat.listener

import io.github.scarger.chat.LowLevelChat
import org.bukkit.ChatColor
import org.bukkit.event.EventHandler
import org.bukkit.event.Listener
import org.bukkit.event.player.AsyncPlayerChatEvent

class ChatObserver() : Listener {
    @EventHandler
    fun onPlayerChat(event: AsyncPlayerChatEvent) {
        event.message =
                "${ChatColor.AQUA}Translate @ ${ChatColor.GREEN}${LowLevelChat.context.translator.encrypt(event.message)}"
    }
}
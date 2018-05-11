package io.github.scarger.chat.commands

import io.github.scarger.chat.LowLevelChat
import org.bukkit.ChatColor
import org.bukkit.command.Command
import org.bukkit.command.CommandExecutor
import org.bukkit.command.CommandSender

class TranslateCmd : CommandExecutor {

    override fun onCommand(sender: CommandSender?, command: Command?, label: String?, args: Array<out String>?): Boolean {
        val argLength = args?.size ?: 0
        if(argLength>0) {
            val location: Int =
                    try { Integer.parseInt(args?.get(0)) }
                    catch (e: Exception) {-1}
            val translated: String = if(location<=-1) "NaN" else LowLevelChat.context.translator.translate(location)
            sender?.sendMessage(translated)
        }
        else {
            sender?.sendMessage("${ChatColor.RED}Usage: /translate [message_id]")
        }
        return false
    }

}
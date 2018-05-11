package io.github.scarger.chat

import io.github.scarger.chat.commands.TranslateCmd
import io.github.scarger.chat.util.Translator
import io.github.scarger.chat.listener.ChatObserver
import org.bukkit.ChatColor
import org.bukkit.plugin.java.JavaPlugin
import java.util.*

class LowLevelChat : JavaPlugin() {

    companion object {
        lateinit var context: LowLevelChat
    }

    lateinit var translator: Translator


    override fun onEnable() {
        context = this
        translator = Translator()
        server.pluginManager.registerEvents(ChatObserver(),this)
        getCommand("translate").setExecutor(TranslateCmd())
        logger.info("${ChatColor.GREEN}One step closer.")
    }

    override fun onDisable() {
        translator.dispose()
        logger.info("${ChatColor.RED}Thanks for using LowLevelChat by scarger :)")
    }
}
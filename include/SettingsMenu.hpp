/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SettingsMenu
*/

#include "defs.hpp"

#ifndef SETTINGSMENU_HPP_
#define SETTINGSMENU_HPP_

#include "IMenu.hpp"

class Core;

class SettingsMenu : public IMenu {
    public:
        SettingsMenu(Core *core);
        ~SettingsMenu();

        int buttonAction();
        void drawBackground();
        void run();
        void splashScreen();
        void createButtons();
        void createEditBoxes();
        void useMenuEvents();
        std::tuple<int, int, irr::gui::IGUIButton *, irr::video::ITexture *, irr::video::ITexture *>checkNextButton(int x, int y);
        void stopMenu();
    protected:
    private:
        Core *_core;
        int _stop;
        irr::IrrlichtDevice *_device;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
        irr::gui::IGUIEnvironment *_gui;
        EventManager _receiver;
        irr::video::ITexture *_back_ground;
        irr::video::ITexture *_back_ground_2;
        irr::gui::IGUIEditBox *_text_box;
        irr::gui::IGUIButton *_back_button_gui;
        irr::video::ITexture *_back_button_pre_tx;
        irr::video::ITexture *_back_button_post_tx;
        irr::video::ITexture *_back_button_hover_tx;
        irr::gui::IGUIButton *_apply_button_gui;
        irr::video::ITexture *_apply_button_pre_tx;
        irr::video::ITexture *_apply_button_post_tx;
        irr::video::ITexture *_apply_button_hover_tx;
        irr::gui::IGUIButton *_sound_button_gui;
        irr::video::ITexture *_sound_button_on_tx;
        irr::video::ITexture *_sound_button_off_tx;
        irr::video::ITexture *_sound_button_on_hover_tx;
        irr::video::ITexture *_sound_button_off_hover_tx;
        irr::gui::IGUIButton *_music_button_gui;
        irr::video::ITexture *_music_button_on_tx;
        irr::video::ITexture *_music_button_on_hover_tx;
        irr::video::ITexture *_music_button_off_tx;
        irr::video::ITexture *_music_button_off_hover_tx;
        bool _soundPressed;
        bool _musicPressed;
        std::vector<std::string> _keySetters0;
        std::vector<std::string> _keySetters1;
        std::vector<std::string> _keySetters2;
        std::vector<std::string> _keySetters3;
        std::vector<std::string> _keySetters4;
        std::vector<irr::gui::IGUIEditBox *> _textBoxes0;
        std::vector<irr::gui::IGUIEditBox *> _textBoxes1;
        std::vector<irr::gui::IGUIEditBox *> _textBoxes2;
        std::vector<irr::gui::IGUIEditBox *> _textBoxes3;
        std::vector<irr::gui::IGUIEditBox *> _textBoxes4;
        std::tuple<int, int, irr::gui::IGUIButton *, irr::video::ITexture *, irr::video::ITexture *>_current_button;
        std::vector<std::tuple<int, int, irr::gui::IGUIButton *, irr::video::ITexture *, irr::video::ITexture *>>_button_array;
};

#endif /* !SETTINGSMENU_HPP_ */

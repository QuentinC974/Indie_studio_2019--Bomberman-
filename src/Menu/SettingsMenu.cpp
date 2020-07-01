/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SettingsMenu
*/

#include "Core.hpp"
#include "SettingsMenu.hpp"

SettingsMenu::SettingsMenu(Core *core)
{
    this->_core = core;
    this->_stop = DEFAULT;
    this->_device = this->_core->getWindow()->getDevice();
    this->_driver = this->_core->getWindow()->getDriver();
    this->_smgr = this->_core->getWindow()->getSmgr();
    this->_gui = this->_core->getWindow()->getGui();
    this->_receiver = this->_core->getWindow()->getReceiver();
    this->_back_ground = this->_driver->getTexture("../assets/SETTINGS_BG.png");
    // this->_back_ground_2 = this->_driver->getTexture("../assets/SETTINGS_BG_2.png");
    this->_back_button_gui = nullptr;
    this->_back_button_pre_tx = this->_driver->getTexture("../assets/BACK_PRE.png");
    this->_back_button_post_tx = this->_driver->getTexture("../assets/BACK_POST.png");
    this->_back_button_hover_tx = this->_driver->getTexture("../assets/BACK_HOVER.png");
    this->_apply_button_gui = nullptr;
    this->_apply_button_pre_tx = this->_driver->getTexture("../assets/APPLY_PRE.png");
    this->_apply_button_post_tx = this->_driver->getTexture("../assets/APPLY_POST.png");
    this->_apply_button_hover_tx = this->_driver->getTexture("../assets/APPLY_HOVER.png");
    this->_sound_button_gui = nullptr;
    this->_sound_button_on_tx = this->_driver->getTexture("../assets/SOUND_ON.png");
    this->_sound_button_off_tx = this->_driver->getTexture("../assets/SOUND_OFF.png");
    this->_sound_button_on_hover_tx = this->_driver->getTexture("../assets/SOUND_ON_HOVER.png");
    this->_sound_button_off_hover_tx = this->_driver->getTexture("../assets/SOUND_OFF_HOVER.png");
    this->_music_button_gui = nullptr;
    this->_music_button_on_tx = this->_driver->getTexture("../assets/MUSIC_ON.png");
    this->_music_button_off_tx = this->_driver->getTexture("../assets/MUSIC_OFF.png");
    this->_music_button_on_hover_tx = this->_driver->getTexture("../assets/MUSIC_ON_HOVER.png");
    this->_music_button_off_hover_tx = this->_driver->getTexture("../assets/MUSIC_OFF_HOVER.png");
    this->_soundPressed = false;
    this->_musicPressed = false;
    std::string tmp;
    for (size_t i = 0; i < this->_core->getKeyMap0().size(); i++) {
        tmp = this->_core->getKeyMap0().at(i);
        this->_keySetters0.push_back(tmp);
    }
    for (size_t i = 0; i < this->_core->getKeyMap1().size(); i++) {
        tmp = this->_core->getKeyMap1().at(i);
        this->_keySetters1.push_back(tmp);
    }
    for (size_t i = 0; i < this->_core->getKeyMap2().size(); i++) {
        tmp = this->_core->getKeyMap2().at(i);
        this->_keySetters2.push_back(tmp);
    }
    for (size_t i = 0; i < this->_core->getKeyMap3().size(); i++) {
        tmp = this->_core->getKeyMap3().at(i);
        this->_keySetters3.push_back(tmp);
    }
    for (size_t i = 0; i < this->_core->getKeyMap4().size(); i++) {
        tmp = this->_core->getKeyMap4().at(i);
        this->_keySetters4.push_back(tmp);
    }
}

SettingsMenu::~SettingsMenu()
{
    this->_gui->clear();
}

void SettingsMenu::createButtons()
{
    this->_back_button_gui = this->_gui->addButton(irr::core::rect<irr::s32>(this->_core->getWindow()->getWidth() / 3, this->_core->getWindow()->getHeight() / 3 + 550, this->_core->getWindow()->getWidth() / 2.1, this->_core->getWindow()->getHeight() / 2.6 + 550));
    this->_back_button_gui->setImage(this->_back_button_pre_tx);
    this->_back_button_gui->setPressedImage(this->_back_button_post_tx);
    this->_back_button_gui->setScaleImage();
    this->_back_button_gui->setIsPushButton();
    this->_button_array.push_back(std::make_tuple(0, 1, this->_back_button_gui, this->_back_button_pre_tx, this->_back_button_hover_tx));
    this->_apply_button_gui = this->_gui->addButton(irr::core::rect<irr::s32>(this->_core->getWindow()->getWidth() / 3 + 361, this->_core->getWindow()->getHeight() / 3 + 550, this->_core->getWindow()->getWidth() / 2.1 + 361, this->_core->getWindow()->getHeight() / 2.6 + 550));
    this->_apply_button_gui->setImage(this->_apply_button_pre_tx);
    this->_apply_button_gui->setPressedImage(this->_apply_button_post_tx);
    this->_apply_button_gui->setScaleImage();
    this->_apply_button_gui->setIsPushButton();
    this->_button_array.push_back(std::make_tuple(0, 2, this->_apply_button_gui, this->_apply_button_pre_tx, this->_apply_button_hover_tx));
    this->_current_button = std::make_tuple(0, 2, this->_apply_button_gui, this->_apply_button_pre_tx, this->_apply_button_hover_tx);
    
    this->_sound_button_gui = this->_gui->addButton(irr::core::rect<irr::s32>(500, this->_core->getWindow()->getHeight() / 3 + 550, 550, this->_core->getWindow()->getHeight() / 2.6 + 550));
    this->_sound_button_gui->setImage(this->_sound_button_on_tx);
    this->_sound_button_gui->setPressedImage(this->_sound_button_off_tx);
    if (this->_core->getMusic()->isSoundMuted())
        this->_sound_button_gui->setPressed(true);
    this->_sound_button_gui->setPressedImage(this->_sound_button_off_tx);
    this->_sound_button_gui->setScaleImage();
    this->_sound_button_gui->setIsPushButton();
    this->_button_array.push_back(std::make_tuple(0, 0, this->_sound_button_gui, this->_sound_button_on_tx, this->_sound_button_on_hover_tx));
    
    this->_music_button_gui = this->_gui->addButton(irr::core::rect<irr::s32>(1500, this->_core->getWindow()->getHeight() / 3 + 550, 1550, this->_core->getWindow()->getHeight() / 2.6 + 550));
    this->_music_button_gui->setImage(this->_music_button_on_tx);
    this->_music_button_gui->setPressedImage(this->_music_button_off_tx);
    if (!this->_core->getMusic()->isMusicPlaying())
        this->_music_button_gui->setPressed(true);
    this->_music_button_gui->setScaleImage();
    this->_music_button_gui->setIsPushButton();
    this->_button_array.push_back(std::make_tuple(0, 3, this->_music_button_gui, this->_music_button_on_tx, this->_music_button_on_hover_tx));
}

void SettingsMenu::createEditBoxes()
{
    for (size_t i = 0; i < this->_keySetters0.size(); i++)
        this->_textBoxes0.push_back(this->_gui->addEditBox(std::wstring(this->_keySetters0.at(i).end() - 1, this->_keySetters0.at(i).end()).c_str(), irr::core::rect<irr::s32>(265, 350 + i * 98, 355, 400 + i * 98), true));
    for (size_t i = 0; i < this->_keySetters1.size(); i++)
        this->_textBoxes1.push_back(this->_gui->addEditBox(std::wstring(this->_keySetters1.at(i).end() - 1, this->_keySetters1.at(i).end()).c_str(), irr::core::rect<irr::s32>(265 + 382, 350 + i * 98, 355 + 382, 400 + i * 98), true));
    for (size_t i = 0; i < this->_keySetters2.size(); i++)
        this->_textBoxes2.push_back(this->_gui->addEditBox(std::wstring(this->_keySetters2.at(i).end() - 1, this->_keySetters2.at(i).end()).c_str(), irr::core::rect<irr::s32>(265 + 382 * 2, 350 + i * 98, 355 + 382 * 2, 400 + i * 98), true));
    for (size_t i = 0; i < this->_keySetters3.size(); i++)
        this->_textBoxes3.push_back(this->_gui->addEditBox(std::wstring(this->_keySetters3.at(i).end() - 1, this->_keySetters3.at(i).end()).c_str(), irr::core::rect<irr::s32>(265 + 382 * 3, 350 + i * 98, 355 + 382 * 3, 400 + i * 98), true));
    for (size_t i = 0; i < this->_keySetters4.size(); i++)
        this->_textBoxes4.push_back(this->_gui->addEditBox(std::wstring(this->_keySetters4.at(i).end() - 1, this->_keySetters4.at(4).end()).c_str(), irr::core::rect<irr::s32>(265 + 382 * 4, 350 + i * 98, 355 + 382 * 4, 400 + i * 98), true));
}

int SettingsMenu::buttonAction()
{
    if (this->_back_button_gui->isPressed()) {
        this->_core->getMusic()->loadSound("click", 1);
        this->_core->setBackToMainMenu(true);
        this->_back_button_gui->setPressed(false);
        return EXIT;
    }
    if (this->_apply_button_gui->isPressed()) {
        this->_core->getMusic()->loadSound("click", 1);
        this->_apply_button_gui->setPressed(false);
    }
    if (this->_sound_button_gui->isPressed() && !this->_soundPressed) {
        this->_core->getMusic()->loadSound("click", 1);
        this->_core->getMusic()->muteSound();
        this->_soundPressed = true;
    }
    if (!this->_sound_button_gui->isPressed() && this->_soundPressed) {
        this->_core->getMusic()->loadSound("click", 1);
        this->_core->getMusic()->unmuteSound();
        this->_soundPressed = false;
    }
    if (this->_music_button_gui->isPressed() && !this->_musicPressed) {
        this->_core->getMusic()->loadSound("click", 1);
        this->_core->getMusic()->stopMusic();
        this->_core->getMusic()->muteMusic();
        this->_musicPressed = true;
    }
    if (!this->_music_button_gui->isPressed() && this->_musicPressed) {
        this->_core->getMusic()->loadSound("click", 1);
        this->_core->getMusic()->unmuteMusic();
        this->_core->getMusic()->loadMusic("menu");
        this->_musicPressed = false;
    }
    return DEFAULT;
}

std::tuple<int, int, irr::gui::IGUIButton *, irr::video::ITexture *, irr::video::ITexture *>SettingsMenu::checkNextButton(int x, int y)
{
    for (std::tuple<int, int, irr::gui::IGUIButton *, irr::video::ITexture *, irr::video::ITexture *> button : this->_button_array) {
        if (std::get<0>(button) == x && std::get<1>(button) == y)
            if (!std::get<2>(button)->isEnabled()) {
                return checkNextButton(x + (x - std::get<0>(this->_current_button)), y + (y - std::get<1>(this->_current_button)));
            } else
                return button;
    }
    for (int i = y; i >= 0; i--) {
        for (std::tuple<int, int, irr::gui::IGUIButton *, irr::video::ITexture *, irr::video::ITexture *> button : this->_button_array) {
            if (std::get<0>(button) == x && std::get<1>(button) == i)
                if (!std::get<2>(button)->isEnabled()) {
                    return checkNextButton(x + (x - std::get<0>(this->_current_button)), y + (y - std::get<1>(this->_current_button)));
                } else
                    return button;
        }
    }
    return this->_current_button;
}

void SettingsMenu::drawBackground()
{
    this->_driver->draw2DImage(this->_back_ground, irr::core::rect<irr::s32>(0, 0, this->_core->getWindow()->getWidth(), this->_core->getWindow()->getHeight()), irr::core::rect<irr::s32>(0, 0, BG_WIDTH, BG_HEIGHT));
    // this->_driver->draw2DImage(this->_back_ground_2, irr::core::rect<irr::s32>(0, 200, this->_core->getWindow()->getWidth(), this->_core->getWindow()->getHeight() / 1.2), irr::core::rect<irr::s32>(0, 0, 1362, 558));
}

void SettingsMenu::stopMenu()
{
    this->_stop = EXIT;
}

void SettingsMenu::useMenuEvents()
{
    std::get<2>(this->_current_button)->setImage(std::get<3>(this->_current_button));
    if (this->_core->getWindow()->getReceiver().IsKeyDown((irr::EKEY_CODE)this->_core->getKeyMap1().at(0)))
        this->_current_button = checkNextButton(std::get<0>(this->_current_button) - 1, std::get<1>(this->_current_button));
    if (this->_core->getWindow()->getReceiver().IsKeyDown((irr::EKEY_CODE)this->_core->getKeyMap1().at(1)))
        this->_current_button = checkNextButton(std::get<0>(this->_current_button), std::get<1>(this->_current_button) - 1);
    if (this->_core->getWindow()->getReceiver().IsKeyDown((irr::EKEY_CODE)this->_core->getKeyMap1().at(2)))
        this->_current_button = checkNextButton(std::get<0>(this->_current_button) + 1, std::get<1>(this->_current_button));
    if (this->_core->getWindow()->getReceiver().IsKeyDown((irr::EKEY_CODE)this->_core->getKeyMap1().at(3)))
        this->_current_button = checkNextButton(std::get<0>(this->_current_button), std::get<1>(this->_current_button) + 1);
    if (this->_core->getWindow()->getReceiver().IsKeyDown((irr::EKEY_CODE)this->_core->getKeyMap0().at(1)) && std::get<2>(this->_current_button)->isEnabled())
        std::get<2>(this->_current_button)->setPressed(!std::get<2>(this->_current_button)->isPressed());
    if (std::get<2>(this->_current_button) == this->_sound_button_gui && !std::get<2>(this->_current_button)->isPressed())
        std::get<4>(this->_current_button) = this->_sound_button_on_hover_tx;
    if (std::get<2>(this->_current_button) == this->_sound_button_gui && std::get<2>(this->_current_button)->isPressed())
        std::get<4>(this->_current_button) = this->_sound_button_off_hover_tx;
    if (std::get<2>(this->_current_button) == this->_music_button_gui && !std::get<2>(this->_current_button)->isPressed())
        std::get<4>(this->_current_button) = this->_music_button_on_hover_tx;
    if (std::get<2>(this->_current_button) == this->_music_button_gui && std::get<2>(this->_current_button)->isPressed())
        std::get<4>(this->_current_button) = this->_music_button_off_hover_tx;
    if (std::get<2>(this->_current_button)->isPressed())
        std::get<2>(this->_current_button)->setPressedImage(std::get<4>(this->_current_button));
    else
        std::get<2>(this->_current_button)->setImage(std::get<4>(this->_current_button));
    if (this->_core->getWindow()->getReceiver().IsKeyDown((irr::EKEY_CODE)this->_core->getKeyMap0().at(0)))
        this->_back_button_gui->setPressed(true);
}

void SettingsMenu::run()
{
    createButtons();
    // createEditBoxes();
    while (this->_device->run() && this->_stop != EXIT) {
        this->_driver->beginScene(true, true, irr::video::SColor(0, 0, 0, 0));
        drawBackground();
        useMenuEvents();
        this->_stop = buttonAction();
        this->_smgr->drawAll();
        this->_gui->drawAll();
        this->_driver->endScene();
    }
}

void SettingsMenu::splashScreen()
{
}
# VSColors
VS & VSCode dark but colorful settings. Distinguishes member functions, static functions, global functions, member variables, static variables, global variables, macros, preprocessor directives, parameters, operators, etc.

![](https://github.com/zdenyhraz/VSColors/blob/master/pics/colors1.PNG?raw=true "colors1")

## Terminal
- install WSL
- install Ubuntu
- install VSCode WSL extension
- sudo apt-get install zsh
- sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
- Install fonts & follow instructions: https://github.com/romkatv/powerlevel10k#meslo-nerd-font-patched-for-powerlevel10k Fonts -> Manual font installation (Visual Studio Code, Windows Terminal)
- git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ${ZSH_CUSTOM:-$HOME/.oh-my-zsh/custom}/themes/powerlevel10k
- Set ZSH_THEME="powerlevel10k/powerlevel10k" in ~/.zshrc
- Set plugins=(git zsh-autosuggestions zsh-syntax-highlighting) in ~/.zshrc
- git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting
- git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions
- p10k configure

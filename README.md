 English | [Russian](README-RU.md) | [Czech](README-CZ.md) | [Spanish](README-ES.md) | [简体中文](README-CN.md)
<p>
<a href="https://discord.gg/GpBrjrebd5"><img src=https://img.shields.io/badge/Discord_Server-3670a0?style=for-the-badge&logo=discord&logoColor=white></a>
</p>

# GD-Decompiled
 An attempt to get the source code for Geometry Dash through reverse engineering and decompiling the game.  
I Calloc Have forked this repository for decompling other sources within 2.2 and beyond while wylie is off doing other things (Until he makes a 2.2 repository)
For now I shall dump what I do have for 2.204 and android v2.205 in here. Feel free to submit pull requests here so I can look at them I would like this to be an official repo for the people of geode to start using temporarly...

## Update 
- 2.206 is coming soon so we will make another repository possibly for that version and I might end up redoing everything due to how messy this repo feels to me...
- Even Better, Wylie told me he will be working on this stuff in the future so I will be archiving this repo up when that happens and then start moving everything that I have done to it. 

## Tools Used
See this [repo](https://github.com/CallocGD/Geometry-Dash-Miscellaneous-Decomp-Tools)


## My Goals with this fork
- To Finish what wyliemaster set out to do
- To have all of `Manager` class components completely decompiled and reverse engineered as they can be the most difficult parts of gd's code to understand. They also make up a large chunk of the game and have numerous functions involved with them and I am also working on providing bindings to geode at the same time as more parts and variable names are being discovered. Understanding these componentes will allow for better mods to be made in the future as well as for understanding how http requests are made (Even though these have been well documentented already thanks to wyliemaster).
- I am Using Andorid Version 2.205 with ghidra and some help from [geode's bindings](https://github.com/geode-sdk/bindings) to help assist me with reverse engineering GD. I will be altering some of Wylie's original class member names in order to match with geode's class member names to help them mod GD.
- I will mainly be reverse engineering class objects that are not well understood by the community or haven't been fully reverse engineered yet in order to educate anyone interested...
- The Good news is that most of everyone has already found most of the puzzle pieces missing , I just have to put them all together and make sure they all fit.
- Eventually making everything compile and then verifying it off with a checksum however we are not to the point where these checks can be reasonably made.

## How Can I Contribute?
- Unlike WylieMaster, I'm not very skilled yet at finding and naming class members by myself and I have chosen to simply leave that puzzle up to the Geode and it's many contributors and volunteers so that nothing remains in conflict. So in trade, the more class-members you find and add to the [geode bindings](https://github.com/geode-sdk/bindings) the more class objects and functions I will be able to reverse engineer.
- Downloading [Ghidra](https://github.com/NationalSecurityAgency/ghidra) or [IDA Pro](https://hex-rays.com/IDA-pro/) and Reverse engineering some of these class objects and members by youself. I am looking for other contributors besides just myself to volunteer in this effort.
- If you have or find any undocumented objects / class-members / C++ code and fully or even partially reverse engineered functions big and small that are not in this repository or it's code. I higly suggest and urgently encourage you fork this repository and send me a pull request with the objects and reverse engineered code that you want in here. I always try my very best to give credit to people that make these sorts of discoveries. You can also send me a dm about important findings on discord.
- Joining my discord server linked above. We are constantly needing/looking for help with unsolved functions.
- finding Robtop code-snippets (aka. freebies)


## IMPORTANT

- This Project is intended to be used as reference material to assist with modding.
- Educating people on how geometry dash is built under the hood. 
- This repository is <b>not</b> a matching decompilation however we strive to be as correct as possible. Code is code and at the end of the day we don't really know how it was actually written by Robtop.

- This code is NOT intended to be compiled (Yet) and I Refuse to provide you game assets when we reach the point of compilation and verification of executable files. I don't condone pirating the game!! I sure hope you bought it with your own money first!
 
- I am <b>Primarly hunting for Client-Side Vulnerabilities / Exploits & (CVEs)</b> there's no bounties. There's really no vulnerabilities left Server-side anymore when it comes to this stuff and I've considered documenting stuff such as comment bans, the firewall and other micellaneous stuff that happens on the server's end since I've been programming & interacting with the server for a pretty long time actually.

- I am mainly decompiling for components that I can decompile within my own abilities or limits, if there is a `TODO` label on something I may/(may not) come back to it. This means I except either me or someone else to get out of their seat and try to reverse engineer that function. Some of these class Objects are extemely large such as the `GameObject` which are going to require Teamwork to decompile. Some Functions are puzzles and mazes of their own. Hence why I am saying this now.


## Buy GD

if for some reason you haven't already I recommend you go and buy GD

- [Android](https://play.google.com/store/apps/details?id=com.robtopx.geometryjump&hl=en_GB&gl=US)
- [IOS](https://apps.apple.com/us/app/geometry-dash/id625334537)
- [windows/mac](https://store.steampowered.com/app/322170/Geometry_Dash/)

## want to know more about the game?

if you want to know about the game and how various aspects work, you can find documentation [here](https://github.com/Wyliemaster/gddocs)
NOTE: Documentation is mainly from 2.11 at the moment and may need to be updated since new stuff has been added like levellists and more...

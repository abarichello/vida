FROM debian:jessie-slim AS toolchain_base

LABEL author="artur@barichello.me"

RUN apt-get update && \
    apt-get install -y apt-utils && \
    apt-get install -y --no-install-recommends sudo ca-certificates pkg-config curl wget bzip2 xz-utils make git bsdtar doxygen gnupg && \
    apt-get clean
RUN wget https://github.com/devkitPro/pacman/releases/download/devkitpro-pacman-1.0.1/devkitpro-pacman.deb && \
    dpkg -i devkitpro-pacman.deb && \
    rm devkitpro-pacman.deb && \
    dkp-pacman -Scc --noconfirm

ENV DEVKITPRO=/opt/devkitpro
ENV PATH=${DEVKITPRO}/tools/bin:$PATH

# ---

FROM toolchain_base AS devkitarm

RUN dkp-pacman -Syyu --noconfirm 3ds-dev nds-dev gp32-dev gba-dev nds-portlibs && \
    dkp-pacman -S --needed --noconfirm `dkp-pacman -Slq dkp-libs | grep '^3ds-'` && \
    dkp-pacman -Scc --noconfirm
ENV DEVKITARM=${DEVKITPRO}/devkitARM

# ---

# TODO:
# Install projects deps

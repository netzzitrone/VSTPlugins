---
lang: ja
...

# CubicPadSynth
![](img/cubicpadsynth.png)

<ruby>CubicPadSynth<rt>キュービック パッドシンセ</rt></ruby> は PADsynth アルゴリズムを使ってオシレータのウェーブテーブルを生成するシンセサイザです。キュービック補間を使っているので、可聴域以下の低い周波数でもわりと滑らかな音が出ます。波形を直接描画できる LFO もついています

- [CubicPadSynth 0.1.5 をダウンロード - VST® 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/LatticeReverb0.1.0/CubicPadSynth0.1.5.zip) <img
  src="img/VST_Compatible_Logo_Steinberg_negative.svg"
  alt="VST compatible logo."
  width="60px"
  style="display: inline-block; vertical-align: middle;">
- [プリセットをダウンロード (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/BarBoxFocusFix/CubicPadSynthPresets.zip)

CubicPadSynth を使うには CPU が AVX 以降の SIMD 命令セットをサポートしている必要があります。

パッケージには次のビルドが含まれています。

- Windows 64bit
- Linux 64bit
- macOS 64bit

Mac を持っていないので、 macOS ビルドはテストできていません。もしバグを見つけたときは [GitHub のリポジトリ](https://github.com/ryukau/VSTPlugins)に issue を作るか、 `ryukau@gmail.com` までメールを送っていただければ対応します。

Linux ビルドは Ubuntu 18.0.4 でビルドしています。また REAPER 6.03 で動作確認を行いました。 Bitwig 3.1.2 では GUI が真っ黒になるバグがあるようです。

## インストール
### プラグイン
名前が `.vst3` で終わるディレクトリを OS ごとに決められた位置に配置してください。

- Windows では `/Program Files/Common Files/VST3/` に配置します。
- Linux では `$HOME/.vst3/` に配置します。
- macOS では `/Users/$USERNAME/Library/Audio/Plug-ins/VST3/` に配置します。

DAW によっては上記とは別に VST3 をインストールできるディレクトリを提供していることがあります。詳しくは利用している DAW のマニュアルを参照してください。

### プリセット
解凍して出てきたディレクトリを OS ごとに決められた位置に配置すると使えるようになります。

- Windows : `/Users/$USERNAME/Documents/VST3 Presets/Uhhyou`
- Linux : `$HOME/.vst3/presets/Uhhyou`
- macOS : `/Users/$USERNAME/Library/Audio/Presets/Uhhyou`

プリセットディレクトリの名前はプラグインと同じである必要があります。 `Uhhyou` ディレクトリが無いときは作成してください。

### Windows
プラグインが DAW に認識されないときは C++ redistributable をインストールしてみてください。インストーラは次のリンクからダウンロードできます。ファイル名は `vc_redist.x64.exe` です。

- [The latest supported Visual C++ downloads](https://support.microsoft.com/en-us/help/2977003/the-latest-supported-visual-c-downloads)

### Linux
Ubuntu 18.0.4 では次のパッケージのインストールが必要です。

```bash
sudo apt install libxcb-cursor0  libxkbcommon-x11-0
```

もし DAW がプラグインを認識しないときは、下のリンクの `Package Requirements` を参考にして VST3 に必要なパッケージがすべてインストールされているか確認してみてください。

- [VST 3 Interfaces: Setup Linux for building VST 3 Plug-ins](https://steinbergmedia.github.io/vst3_doc/vstinterfaces/linuxSetup.html)

REAPER の Linux 版がプラグインを認識しないときは `~/.config/REAPER/reaper-vstplugins64.ini` を削除して REAPER を再起動してみてください。

## 操作
操作できる箇所を右クリックすると DAW によって提供されているコンテキストメニューを開くことができます。

つまみとスライダーでは次の操作ができます。

- Ctrl + 左クリック : 値のリセット。
- Shift + 左ドラッグ : 細かい値の変更。

`Octave` 、 `Seed` などで使われている数値スライダーでは、上記に加えて次の操作ができます。

- ホイールクリック : 最小値、最大値の切り替え。

Wavetable タブの `Gain`, `Width`, `Pitch`, `Phase` と Main タブの `LFO Wave` で使われている青い縦棒が並んだコントロール (BarBox) ではショートカットが使えます。ショートカットは BarBox を左クリックしてフォーカスすると有効になります。フォーカス後にマウスカーソルを BarBox の領域外に移動させると、ショートカットが一時的に無効になります。ショートカットによって変更されるパラメータはカーソルの位置によって変更できます。 Information タブを開くとショートカットの一覧を見ることができます。

| 入力                                    | 操作                                       |
| --------------------------------------- | ------------------------------------------ |
| <kbd>Ctrl</kbd> + <kbd>Left Click</kbd> | デフォルト値にリセット                     |
| <kbd>Mouse Middle Drag</kbd>            | 直線の描画                                 |
| <kbd>d</kbd>                            | すべての値をデフォルト値にリセット         |
| <kbd>D</kbd>                            | 最小値・中央値・最大値の切り替え           |
| <kbd>e</kbd>                            | 低域の強調                                 |
| <kbd>E</kbd>                            | 高域の強調                                 |
| <kbd>f</kbd>                            | ローパスフィルタ                           |
| <kbd>F</kbd>                            | ハイパスフィルタ                           |
| <kbd>i</kbd>                            | 値の反転 (最小値を保存)                    |
| <kbd>I</kbd>                            | 値の反転 (最小値を 0 に設定)               |
| <kbd>n</kbd>                            | 最大値を 1 に正規化 (最小値もスケーリング) |
| <kbd>N</kbd>                            | 最大値を 1 に正規化 (最小値を 0 に設定)    |
| <kbd>p</kbd>                            | ランダムに並べ替え                         |
| <kbd>r</kbd>                            | ランダマイズ                               |
| <kbd>R</kbd>                            | まばらなランダマイズ                       |
| <kbd>s</kbd>                            | 降順にソート                               |
| <kbd>S</kbd>                            | 昇順にソート                               |
| <kbd>t</kbd>                            | 少しだけランダマイズ                       |
| <kbd>,</kbd> (Comma)                    | 左に回転                                   |
| <kbd>.</kbd> (Period)                   | 右に回転                                   |
| <kbd>1</kbd>                            | すべての値を低減                           |
| <kbd>2</kbd>-<kbd>9</kbd>               | インデックスが 2n-9n の値を低減            |

## 注意
`Refresh LFO` あるいは `Refresh Table` ボタンを押すと音が止まります。発音中のノートも全て停止します。

## ウェーブテーブルの仕様
1 つのウェーブテーブルの長さは `2^18` サンプルです。

各 MIDI ノートと 20000Hz までのピッチベンドができるように帯域制限された 136 のウェーブテーブルが生成されます。約 21100 Hz より音程が高くなると完全な無音になります。 21100 は MIDI ノート番号 136 から求められた値です。 MIDI ノート番号 137 の周波数は 22050 Hz よりも高いので、サンプリング周波数が 44100 Hz のときにエイリアシングが起こります。したがって一つ小さい 136 を使っています。

音程の基本周波数が 8.18 Hz (MIDI ノート番号 0) より低くなると高域の周波数成分が失われた音になります。ただし、キュービック補間によって生じるノイズによって、周波数成分の値が完全に 0 にはならないことがあります。

```
noteToFreq(note) := 440 * pow(2, (note - 69) / 12)
noteToFreq(0) = 8.175798915643707
noteToFreq(136) = 21096.16364242367
noteToFreq(137) = 22350.606811712252
```

ウェーブテーブルは `136 * 2^18` の 2 次元配列として表現されています。オシレータの位相と周波数から求められるテーブル上の座標についてバイキュービック補間で値を求めています。

ウェーブテーブルが大きめなので、メモリが遅いとフレーム落ち ([xrun](https://alsa.opensrc.org/Xruns)) の可能性が高まります。音程が高くなるほどアクセスパターンがランダムに近くなるので、環境によっては重くなります。

- [Alsa Opensrc Org - Independent ALSA and linux audio support site](https://alsa.opensrc.org/Xruns)
- [linux - What are XRuns? - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/199498/what-are-xruns)

## PADsynth アルゴリズムの概要
CubicPadSynth は [ZynAddSubFX](https://zynaddsubfx.sourceforge.io/) や [Yoshimi](http://yoshimi.sourceforge.net/) で使われている PADsynth アルゴリズムでウェーブテーブルを合成しています。

適当に位相をランダマイズした周波数成分を逆 DFT すると一方の端ともう一方の端が滑らかにつながった周期的な波形になります。PADsynth アルゴリズムはこの性質を使って滑らかにループするウェーブテーブルを合成します。

周波数成分の合成ではプロファイルと呼ばれている適当な関数をスペクトラム上に並べます。 CubicPadSynth のプロファイルはオリジナルの PADsynth アルゴリズムと同じ正規分布曲線を使っています。プロファイルの中心となる周波数は任意に決めることができます。 CubicPadSynth ではデフォルトで `Base Freq.` で指定した基本周波数とその倍音にあたる周波数を使います。

![](img/padsynth.svg)

- [PADsynth algorithm](https://zynaddsubfx.sourceforge.io/doc/PADsynth/PADsynth.htm)

## ブロック線図
図が小さいときはブラウザのショートカット <kbd>Ctrl</kbd> + <kbd>マウスホイール</kbd> や、右クリックから「画像だけを表示」などで拡大できます。

図で示されているのは大まかな信号の流れです。実装と厳密に対応しているわけではないので注意してください。

![](img/cubicpadsynth.svg)

## パラメータ
### Main タブ
![](img/cubicpadsynth.png)

#### Tuning
Octave, Semi, Milli

:   全体の音の高さを変更します。

    - `Octave`: オクターブ
    - `Semi`: 半音
    - `Milli`: 半音の 1 / 1000 。 1 / 10 セント。

ET, A4 [Hz]

:   音律を変更します。

    `ET` は Equal Temperature (平均律) の略です。 `ET` が 12 のときは 12 平均律となります。 `ET` を 12 よりも小さくすると無音になる範囲が増えるので注意してください。

    `A4 [Hz]` は、音程 A4 の周波数です。

#### Gain
A, D, S, R

:   音量エンベロープのパラメータです。

    - `A` (Attack) : 鍵盤を押した瞬間から最大音量になるまでのアタック時間。
    - `D` (Decay) : 最大音量からサステイン音量になるまでのディケイ時間。
    - `S` (Sustain) : アタックとディケイが終わった後に鍵盤を押し続けているときのサステイン音量。
    - `R` (Release) : 鍵盤から指を離したあとに音量が 0 になるまでのリリース時間。

Gain

:   音量を変更します。

#### Lowpass
現在の音程よりも倍音の少ないウェーブテーブルを使うことで疑似的にローパスフィルタを再現しています。

カットオフ周波数の計算式は次のようになっています。

```
cut = Cutoff * 128
keyFollowRange = Cutoff * (nTable - pitch)
lowpassPitch = (cut + KeyFollow * (keyFollowRange - cut)) - lowpassEnvelope * Amount;
if (lowpassPitch < 0) lowpassPitch = 0

noteToFreq(note) := 440 * Math.pow(2, (note - 69) / 12)
range  = noteToFreq(nTable)
lpFreq = noteToFreq(midiNote + lowpassPitch)
ntFreq = noteToFreq(midiNote)
cutoffFrequency = (1 + (range - lpFreq) / range) * ntFreq
```

`lpCut` の計算に使っている 128 は MIDI ノート番号の範囲 + 1 から適当に決めた値です。また `nTable = 136` です。

Cutoff

:   フィルタのカットオフ周波数を変更します。

KeyFollow

:   右いっぱいに回すと音程に関わらず倍音の数がだいたい等しくなるようにカットオフ周波数を調節します。左いっぱいに回すと音程に関わらず `Cutoff` で設定されたカットオフ周波数を使います。

A, D, S, R, Amount

:   フィルタのカットオフ周波数を変調するエンベロープのパラメータです。 `Amount` は `Cutoff` への変調量です。

#### Pitch
A, D, S, R, Amount

:   ノートごとにピッチを変調するエンベロープのパラメータです。

Negative

:   エンベロープの符号を反転します。

#### Unison
nUnison

:   ユニゾンに使うボイスの数です。

    `Misc.` の `nVoice` を増やすことで `nUnison` が大きいときに起こるリリースの途切れを減らすことができますが、引き換えに動作が重くなります。

Detune, Random Detune

:   `Detune` はユニゾンに使われているボイスのピッチをずらす量です。

    `Random Detune` のチェックを入れると、ピッチがずれる量がノートオンごとにランダムに変わるようになります。

    ```
    random = RandomDetune ? rand() : 1
    detune = pitch * (1 + random * unisonIndex * Detune)
    ```

GainRnd

:   ユニゾンに使われているボイスの音量をランダムに変更する量です。

Phase

:   ユニゾンに使われているボイスの位相をランダムに変更する量です。

    Phase セクションの `Reset` にチェックが入っていないとき、この値は無視されます。

Spread, Spread Type

:   `Spread` はユニゾンの左右の広がりの量です。

    `Spread Type` でボイスのピッチに応じたパンの割り当て方を選択できます。

    - `Alternate L-R`: `Ascend L -> R` と `Ascend R -> L` を交互に変更。
    - `Alternate M-S`: `HighOnMid` と `HighOnSide` を交互に変更。
    - `Ascend L -> R`: 左から右に向かってピッチが上昇。
    - `Ascend R -> L`: 右から左に向かってピッチが上昇。
    - `HighOnMid`: 端から中央に向かってピッチが上昇。
    - `HighOnSide`: 中央から端に向かってピッチが上昇。
    - `Random`: ランダムに生成したパンを割り当て。偏ることがあります。
    - `RotateL`: ノートオンごとに割り当てを左に回転。
    - `RotateR`: ノートオンごとに割り当てを右に回転。
    - `Shuffle`: 均一に並べたパンをランダムに割り当て。

#### LFO
Refresh LFO

:   現在の `LFO Wave` のパラメータに基づいて LFO のウェーブテーブルを更新します。

    ウェーブテーブルの更新中は音が止まるので注意してください。発音中のノートも全て停止します。

Interpolation

:   LFO のウェーブテーブルの補間の種類です。

    ![](img/interpolation_type.png)

Tempo, Multiply

:   LFO の周波数をテンポに応じた形で指定します。 `Tempo` の下の数字が音符の長さ、上の数字が音符の数です。例えば上が 6 、下が 8 なら 8 分音符の 6 個分の長さが LFO の 1 周期になります (6 / 8 拍子)。

    `Multiply` は `Tempo` から計算された周波数に掛け合わされる値です。

    ```
    // (60 秒) * (4 拍子) = 240 。
    lfoFrequency = Multiply * (BPM / 240) / (TempoUpperNumeral / TempoLowerNumeral)
    ```

Retrigger

:   チェックを入れると、ノートオンごとに LFO の位相をリセットします。

Amount

:   LFO でピッチを変調する量です。

Lowpass

:   LFO にかけるローパスフィルタのカットオフ周波数を変更します。

LFO Wave

:   LFO の波形です。

#### Phase
Phase

:   オシレータの初期位相です。

Reset

:   チェックを入れると、ノートオンのたびにオシレータの位相を `Phase` で指定した値にリセットします。

Random

:   チェックを入れると、ノートオンごとに位相をランダマイズします。 `Phase` で指定した値がランダマイズの範囲になります。

#### Misc.
Smooth

:   特定の値を変更したときに、変更前の値から変更後の値に移行する時間（秒）です。

    `Smooth` と関連するパラメータのリストです。 `*` はワイルドカードです。

    - Tuning セクションの全て
    - Gain
      - `S`
      - `Gain`
    - Lowpass
      - `Cutoff`
      - `KeyFollow`
      - `S`
      - `Amount`
    - Pitch
      - `S`
      - `Amount`
      - `Negative`
    - LFO
      - `Tempo`
      - `Multiply`
      - `Amount`
      - `Lowpass`
    - Phase
      - `Phase`

nVoice

:   最大同時発音数です。

Pool

:   チェックを入れると、現在の発音数が同時最大発音数に近づいたときに、音量の最も小さいボイスをリリースします。ノートオン時に生じるプチノイズの低減に使えます。

### Wavetable タブ
![](img/cubicpadsynth_wavetable_tab.png)

#### 倍音コントロール
Gain

:   プロファイルの高さです。

Width

:   プロファイルの幅です。

Pitch

:   プロファイルの周波数にかけ合わせる値です。

Phase

:   プロファイルの位相をランダマイズする量です。

#### Pitch
Base Freq.

:   ウェーブテーブルのレンダリング時の基本周波数です。この値が小さいとマスターピッチのチューニングが狂うことがあるので注意してください。

Multiply, Modulo

:   プロファイルの周波数を変更します。

    ```
    profileFrequency = mod(
      BaseFreq * profileIndex * overtonePitch * Multiply,
      440 * pow(2, (Modulo - 69) / 12)
    )
    ```

Random

:   チェックを入れると、倍音コントロールの `Pitch` で指定された値を無視して、プロファイルの周波数をランダマイズします。

#### Spectrum
Expand

:   スペクトラムを周波数軸に沿って拡大・縮小するスケーリング係数です。

    ![](img/expand.svg)

Shift

:   スペクトラムを左右にシフトする量です。

    ![](img/shift.svg)

Comb

:   `Comb` の値が 1 以上のとき、プロファイルをくし状に変形します。値はくしのすき間の間隔です。

    ![](img/comb.png)

Shape

:   `Shape` の値を指数として、プロファイルの形をべき乗によって変更します。

    ```
    shapedProfile = powf(profile, shape);
    ```

Invert

:   スペクトラムの絶対値の最大値が 0 、 0 が絶対値の最大値になるように反転します。符号は保持されます。位相は考慮していません。

    ```
    maxRe = max(abs(spectrumRe))
    maxIm = max(abs(spectrumIm))
    invertedSpectrumRe = spectrumRe - sgn(spectrumRe) * maxRe
    invertedSpectrumIm = spectrumIm - sgn(spectrumIm) * maxIm
    ```

#### Phase
UniformPhase

:   チェックを入れると、プロファイル内での位相を均一にします。

#### Random
Seed

:   乱数のシード値です。この値を変えると生成される乱数が変わります。

#### Modifier
Gain^

:   倍音コントロールの `Gain` をべき乗する値です。

    ```
    profileGain = pow(Gain, Gain^)
    ```

Width\*

:   倍音コントロールの `Width` にかけ合わせる値です。

    ```
    profileWidth = Width * (Width*)
    ```

#### Refresh Table
現在の Wavetable タブのパラメータに基づいてオシレータのウェーブテーブルを更新します。

ウェーブテーブルの更新中は音が止まるので注意してください。発音中のノートも全て停止します。

## チェンジログ
- 0.1.5
  - パラメータの補間を可変サイズのオーディオバッファでも機能する以前の手法に巻き戻した。
- 0.1.4
  - 起動時にパラメータがロードされる前にウェーブテーブルが更新されるバグを修正。
  - LFO ウェーブテーブルの補間が Cubic のときにインデックスが 1 つずれていたバグを修正。
- 0.1.3
  - BarBox のショートカットが効かないバグを修正。
- 0.1.2
  - オートメーションと MIDI マッピングを利用できるように `Refresh Table` と `Refresh LFO` を VST のメッセージからパラメータへと変更。
  - BarBox にフォーカスした後、マウスカーソルが領域外にあるときはショートカットが無効になるように変更。
- 0.1.1
  - 文字列の描画でクラッシュするバグを修正。
- 0.1.0
  - 初期リリース。

### 旧バージョン
- [CubicPadSynth 0.1.4 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/WavetableInitializationBugFix/CubicPadSynth0.1.4.zip)
- [CubicPadSynth 0.1.3 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/LightPadSynth0.1.0/CubicPadSynth0.1.3.zip)
- [CubicPadSynth 0.1.2 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/BarBoxFocusFix/CubicPadSynth0.1.2.zip)
- [CubicPadSynth 0.1.1 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/DrawStringFix/CubicPadSynth0.1.1.zip)

## ライセンス
CubicPadSynth のライセンスは GPLv3 です。 GPLv3 の詳細と、利用したライブラリのライセンスは次のリンクにまとめています。リンクが切れているときは `ryukau@gmail.com` にメールを送ってください。

- [https://github.com/ryukau/VSTPlugins/tree/master/License](https://github.com/ryukau/VSTPlugins/tree/master/License)

### VST® について
VST is a trademark of Steinberg Media Technologies GmbH, registered in Europe and other countries.

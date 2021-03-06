---
lang: ja
...

# SevenDelay
![](img/sevendelay.png)

<ruby>SevenDelay<rt>セブンディレイ</rt></ruby> は7次のラグランジュ補間による分数ディレイと7倍のオーバーサンプリングを使ったステレオディレイです。

- [SevenDelay 0.1.10 をダウンロード - VST® 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/LatticeReverb0.1.0/SevenDelay0.1.10.zip) <img
  src="img/VST_Compatible_Logo_Steinberg_negative.svg"
  alt="VST compatible logo."
  width="60px"
  style="display: inline-block; vertical-align: middle;">
- [プリセットをダウンロード (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/EsPhaser0.1.0/SevenDelayPresets.zip)

パッケージには次のビルドが含まれています。

- Windows 64bit
- Linux 64bit
- macOS 64bit

Mac を持っていないので、 macOS ビルドはテストできていません。もしバグを見つけたときは [GitHub のリポジトリ](https://github.com/ryukau/VSTPlugins)に issue を作るか、 `ryukau@gmail.com` までメールを送っていただければ対応します。

Linux ビルドは Ubuntu 18.0.4 でビルドしています。また Bitwig 3.1.2 と REAPER 6.03 で動作確認を行いました。 Bitwig 3.1.2 では GUI が真っ黒になるバグがあるようです。

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
つまみとスライダーでは次の操作ができます。

- Ctrl + 左クリック : 値のリセット。
- Shift + 左ドラッグ : 細かい値の変更。

## 注意
`Smooth` の値が 0 に近く、 `Allpass Cut` の値を速く動かしすぎたときに、非常に大きな音量のクリックノイズが出力されることがあります。これは `Allpass Cut` で使われているフィルタのカットオフ周波数が、速く、大きく、動きすぎると出力が発散する場合があることが原因です。特別な目的がない限り、`Smooth` パラメータを低く設定しすぎないことを推奨します。

`Time` の値が最小かつ `Feedback` の値が最大に設定されると直流信号が出ることがあります。 `DC Kill` を 1.0 より大きな値に設定することで直流信号を除去できます。

## ブロック線図
図が小さいときはブラウザのショートカット <kbd>Ctrl</kbd> + <kbd>マウスホイール</kbd> や、右クリックから「画像だけを表示」などで拡大できます。

図で示されているのは大まかな信号の流れです。実装と厳密に対応しているわけではないので注意してください。

![](img/sevendelay.svg)

## パラメータ
### Delay
Time

:   ディレイ時間。範囲は 0.0001 から 8.0 です。

    - もし `Sync` が有効で `Time` が 1.0 より小さいときは、ディレイ時間が `Time / 16` 拍に設定されます。
    - もし `Sync` が有効で `Time` が 1.0 以上のときは、ディレイ時間が `floor(2 * Time) / 32` 拍に設定されます。
    - それ以外のときは、ディレイ時間が `time` 秒に設定されます。

Feedback

:   ディレイのフィードバック。範囲は 0.0 から 1.0 です。

Stereo

:   左右のディレイ時間のオフセット。範囲は -1.0 から 1.0 です。

    - もし `Stereo` が 0.0 より小さいときは、左チャンネルのディレイ時間が `timeL * (1.0 + Stereo)` に変更されます。
    - それ以外のときは、右チャンネルのディレイ時間が `timeR * (1.0 + Stereo)` に変更されます。

Wet

:   ディレイ信号の出力音量。範囲は 0.0 から 1.0 。

Dry

:   入力信号の出力音量。範囲は 0.0 から 1.0 。

Sync

:   テンポシンクの切り替え。

Negative

:   負のフィードバックの切り替え。ディレイ時間がとても短いときに役立つかもしれません。

Spread/Pan

:   入力の広がり (In Spread) 、入力のパン (In Pan) 、出力の広がり (Out Spread) 、出力のパン (Out Pan) 。範囲は 0.0 から 1.0 です。

    `In Spread` 、 `Out Spread` はステレオの広がりを制御します。 `In Pan` 、 `Out Pan` はステレオのパンニングを制御します。

    これらのパラメータはパンニングの逆転やピンポンディレイを作るときに使えます。

    - パンニングの逆転を行うには `[InSpread, InPan, OutSpread, OutPan]` を `[0.0, 0.5, 1.0, 0.5]` に設定します。
    - ピンポンディレイにするには `[InSpread, InPan, OutSpread, OutPan]` を `[1.0, 0.5, 0.0, 0.5]` に設定します。

    ```
    panL = clamp(2 * pan + spread - 1.0, 0.0, 1.0)
    panR = clamp(2 * pan - spread, 0.0, 1.0)

    signalL = incomingL + panL * (incomingR - incomingL)
    signalR = incomingL + panR * (incomingR - incomingL)
    ```

Allpass Cut

:   SVF オールパスフィルタのカットオフ周波素。範囲は 90.0 から 20000.0 です。

    `tone` が 20000.0 のとき、フィルタはバイパスされます。

Allpass Q

:   SVF オールパスフィルタのレゾナンス。範囲は 0.00001 から 1.0 です。

    値が大きいほどレゾナンスが強くなります。

DC Kill

:   ハイパスフィルタのカットオフ周波数。範囲は 5.0 から 120.0 です。

    `DC Kill` を 5.0 より大きく設定すればディレイのフィードバックから直流信号を取り除くことができます。

Smooth

:   パラメータ平滑化の度合い。範囲は 0.0 から 1.0 で、単位は秒です。

    パラメータによっては値が急激に変化するとノイズが出ることがあります。 `Smooth` の値を大きめにすることで、値の変化を緩やかにしてノイズを減らすことができます。

### LFO
To Time

:   LFO によるディレイ時間の変調量。範囲は 0.0 から 1.0 です。

To Allpass

:   LFO によるオールパスフィルタのカットオフ周波数の変調量。範囲は 0.0 から 1.0 です。

Frequency

:   LFO の周波数。範囲は 0.01 から 100.0 。

Shape

:   LFO の波形。範囲は 0.01 から 10.0 。

    ```
    sign = 1 if (phase > π),
          -1 if (phase < π),
           0 if (phase == π)
    lfo = sign * abs(sin(phase))^shape
    ```

Phase

:   LFO の位相の初期値。範囲は 0.0 から 2π 。

    LFO の位相はホストが演奏を開始するたびに `Phase` の値にリセットされます。

Hold

:   LFO の位相のホールドの切り替え。ライブ演奏などで役に立つかもしれません。

## チェンジログ
- 0.1.10
  - パラメータの補間を可変サイズのオーディオバッファでも機能する以前の手法に巻き戻した。
- 0.1.9
  - 文字列の描画でクラッシュするバグを修正。
- 0.1.8
  - プラグインタイトルをクリックすると表示されるポップアップの表示方法の変更。
- 0.1.7
  - 非アクティブ化で音が止まるように修正。
- 0.1.6
  - Linux ビルドの GUI を有効化。
- 0.1.5
  - Ableton Live 10.1.6 で特定のノブが揺れ戻るバグを修正。
- 0.1.4
  - 複数の GUI インスタンス間で表示を同期するように変更。
  - スプラッシュスクリーンを開くとクラッシュするバグを修正。
  - リロード時にクラッシュするバグを修正。
  - GUI がホストのオートメーションに応じて更新されるように修正。
- 0.1.3
  - スムーシングのアルゴリズムの値が決められた範囲を超えるバグを修正。
  - LFO Hold のオン・オフが逆転していたバグを修正。
  - オールパスのミキシングにかかっていた LFO による変調を除去。
- 0.1.2
  - 内部のパラメータの構造を変更。
  - UI の見た目を変更。
- 0.1.1
  - Linux ビルドの GUI を無効化。VSTGUI に関するバグが治るまでの応急処置。
  - LFO の `To Allpass` のチューニングを変更。
  - `DC Kill` の最小値を 5.0 Hz に変更。
- 0.1.0
  - 初期リリース。

### 旧バージョン
- [SevenDelay 0.1.9 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/DrawStringFix/SevenDelay0.1.9.zip)
- [SevenDelay 0.1.7 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/EsPhaser0.1.0/SevenDelay0.1.7.zip)
- [SevenDelay 0.1.6 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/LinuxGUIFix/SevenDelay0.1.6.zip)
- [SevenDelay 0.1.5 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/EnvelopedSine0.1.0/SevenDelay0.1.5.zip)
- [SevenDelay 0.1.4 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/IterativeSinCluster0.1.0/SevenDelay0.1.4.zip)

## ライセンス
SevenDelay のライセンスは GPLv3 です。 GPLv3 の詳細と、利用したライブラリのライセンスは次のリンクにまとめています。

- [https://github.com/ryukau/VSTPlugins/tree/master/License](https://github.com/ryukau/VSTPlugins/tree/master/License)

リンクが切れているときは `ryukau@gmail.com` にメールを送ってください。

### VST® について
VST is a trademark of Steinberg Media Technologies GmbH, registered in Europe and other countries.
